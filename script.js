
const screen = document.getElementById("screen");
const history = document.getElementById("history");
const themeToggle = document.getElementById("themeToggle");
const angleToggle = document.getElementById("angleToggle");
const modeText = document.getElementById("modeText");

let degreeMode = true;
let freshResult = false;

// Theme switching
const savedTheme = localStorage.getItem("smartlife-theme");

if (savedTheme === "light") {
    document.body.classList.add("light");
}

updateThemeIcon();

themeToggle.addEventListener("click", () => {
    document.body.classList.toggle("light");

    const theme = document.body.classList.contains("light")
        ? "light"
        : "dark";

    localStorage.setItem("smartlife-theme", theme);
    updateThemeIcon();
});

function updateThemeIcon() {
    themeToggle.textContent =
        document.body.classList.contains("light") ? "🌙" : "☀️";
}

// Degree / Radian switching
angleToggle.addEventListener("click", () => {
    degreeMode = !degreeMode;

    angleToggle.textContent = degreeMode ? "DEG" : "RAD";
    angleToggle.classList.toggle("active", degreeMode);

    modeText.textContent = degreeMode ? "DEG MODE" : "RAD MODE";
});

// Display helper
function getNumber() {
    return Number(screen.value);
}

function formatNumber(number) {
    if (!Number.isFinite(number)) {
        throw new Error("Invalid calculation");
    }

    if (Math.abs(number) < 1e-12) {
        number = 0;
    }

    return Number(number.toPrecision(12)).toString();
}

// Add values to display
function appendValue(value) {
    if (freshResult) {
        if ("0123456789.".includes(value)) {
            screen.value = "0";
        }
        freshResult = false;
    }

    if (screen.value === "0" && "0123456789".includes(value)) {
        screen.value = value;
    } else {
        screen.value += value;
    }
}

// Clear
function clearScreen() {
    screen.value = "0";
    history.textContent = "";
    freshResult = false;
}

// Delete
function deleteLast() {
    if (freshResult) {
        clearScreen();
        return;
    }

    screen.value = screen.value.slice(0, -1) || "0";
}

// Calculate expression
function calculate() {
    try {
        let expression = screen.value;

        // Only allow mathematical characters
        if (!/^[0-9+\-*/().\s^]+$/.test(expression)) {
            throw new Error("Invalid expression");
        }

        // Convert power symbol
        expression = expression.replace(/\^/g, "**");

        const result = Function('"use strict"; return (' +
            expression + ')')();

        history.textContent = screen.value + " =";

        screen.value = formatNumber(result);
        freshResult = true;

    } catch (error) {
        screen.value = "Error";
        freshResult = true;
    }
}

// Factorial
function factorial(number) {
    if (!Number.isInteger(number) || number < 0 || number > 170) {
        throw new Error("Invalid factorial");
    }

    let result = 1;

    for (let i = 1; i <= number; i++) {
        result *= i;
    }

    return result;
}

// Scientific calculations
function scientific(action) {
    try {
        const number = getNumber();
        let result;

        switch (action) {

            case "sin":
                result = Math.sin(
                    degreeMode ? number * Math.PI / 180 : number
                );
                break;

            case "cos":
                result = Math.cos(
                    degreeMode ? number * Math.PI / 180 : number
                );
                break;

            case "tan":
                const angle = degreeMode
                    ? number * Math.PI / 180
                    : number;

                if (Math.abs(Math.cos(angle)) < 1e-12) {
                    throw new Error("Undefined tangent");
                }

                result = Math.tan(angle);
                break;

            case "sqrt":
                if (number < 0) throw new Error("Invalid square root");
                result = Math.sqrt(number);
                break;

            case "square":
                result = number * number;
                break;

            case "log":
                if (number <= 0) throw new Error("Invalid logarithm");
                result = Math.log10(number);
                break;

            case "ln":
                if (number <= 0) throw new Error("Invalid logarithm");
                result = Math.log(number);
                break;

            case "factorial":
                result = factorial(number);
                break;

            case "percent":
                result = number / 100;
                break;

            case "sign":
                result = -number;
                break;

            default:
                return;
        }

        history.textContent = action.toUpperCase() +
            "(" + screen.value + ")";

        screen.value = formatNumber(result);
        freshResult = true;

    } catch (error) {
        screen.value = "Error";
        freshResult = true;
    }
}

// Button clicks
document.querySelectorAll(".btn").forEach(button => {

    button.addEventListener("click", () => {

        const value = button.dataset.value;
        const action = button.dataset.action;

        if (value !== undefined) {
            appendValue(value);
        }

        if (action === "clear") {
            clearScreen();
        }

        else if (action === "delete") {
            deleteLast();
        }

        else if (action === "calculate") {
            calculate();
        }

        else if (action) {
            scientific(action);
        }

    });

});

// Keyboard support
document.addEventListener("keydown", event => {

    const key = event.key;

    if (/^[0-9.]$/.test(key)) {
        appendValue(key);
    }

    else if (["+", "-", "*", "/", "(", ")", "^"].includes(key)) {
        appendValue(key);
    }

    else if (key === "Enter" || key === "=") {
        event.preventDefault();
        calculate();
    }

    else if (key === "Backspace") {
        deleteLast();
    }

    else if (key === "Escape") {
        clearScreen();
    }

    else if (key === "%") {
        scientific("percent");
    }

});
