#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int choice;
    double num1, num2, result, angle, totalMarks, obtainedMarks, percentage;
    long long factorial;

    cout << "==============================" << endl;
    cout << " CALCULATOR" << endl;
    cout << "==============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout<< "5. Square Root" << endl;
    cout<< "6. Power" << endl;
    cout<< "7. Factorial" << endl;
    cout<< "8. sin " << endl;
    cout<< "9. cos" << endl;
    cout<< "10. tan" << endl;
    cout<< "11. sine" << endl;
    cout<< "12. cose" << endl;
    cout<< "13. tangent" << endl;
    cout<< "14. Log" << endl;
    cout<< "15. Percentage" << endl;
    cout<< "16. Exit" << endl;

    cout << "Enter your choice (1-16): ";
    
    cin >> choice;

    switch(choice)
    {
        case 1:
            cout << "Addition selected." << endl;
            // Call the function for Addition
            break;
        case 2:
            cout << "Subtraction selected." << endl;
            // Call the function for Subtraction
            break;
        case 3:
            cout << "Multiplication selected." << endl;
            // Call the function for Multiplication
            break;
        case 4:
            cout << "Division selected." << endl;
            // Call the function for Division
            break;
        case 5:
            cout << "Square Root selected." << endl;
            // Call the function for Square Root
            break;
        case 6:
            cout << "Power selected." << endl;
            // Call the function for Power
            break;
        case 7:
            cout << "Factorial selected." << endl;
            // Call the function for Factorial
            break;
        case 8:
            cout << "Sine selected." << endl;
            // Call the function for Sine
            break;
        case 9:
            cout << "Cosine selected." << endl;
            // Call the function for Cosine
            break;
        case 10:
            cout << "Tangent selected." << endl;
            // Call the function for Tangent
            break;
        case 11:
            cout << "Sine (in degrees) selected." << endl;
            // Call the function for Sine (in degrees)
            break;
        case 12:
            cout << "Cosine (in degrees) selected." << endl;
            // Call the function for Cosine (in degrees)
            break;
        case 13:
            cout << "Tangent (in degrees) selected." << endl;
            // Call the function for Tangent (in degrees)
            break;
        case 14:
            cout << "Logarithm selected." << endl;
            // Call the function for Logarithm
            break;
        case 15:
            cout << "Percentage selected." << endl;
            // Call the function for Percentage
            break;
        case 16:
            cout << "Exiting the calculator." << endl;
            break;
        default:
            cout << "Invalid choice. Please select a valid option." << endl;
            break;
    }

    switch(choice)
    {
        case 1:
        cout << "Enter two numbers: ";
        cin>>num1>>num2;
        cout<<"The sum is: "<<num1+num2<<endl;
        break;
    case 2:
        cout << "Enter two numbers: ";
        cin>>num1>>num2;
        cout<<"The difference is: "<<num1-num2<<endl;
        break;
        case 3:
        cout << "Enter two numbers: ";
        cin>>num1>>num2;
        cout<<"The product is: "<<num1*num2<<endl;
        break;
    case 4:
        cout << "Enter two numbers: ";
        cin>>num1>>num2;
        if(num2 == 0)
        {
            cout << "Error: Division by zero is not allowed." << endl;
        }
        else
        {
            cout<<"The quotient is: "<<num1/num2<<endl;
        }
        break;

    case 5:
        cout << "Enter a number: ";
        cin>>num1;
        if(num1 < 0)
        {
            cout << "Error: Square root of a negative number is not defined." << endl;
        }
        else
        {
            cout<<"The square root is: "<<sqrt(num1)<<endl;
        }
        break;

        case 6:
        cout << "Enter a base and exponent: ";
        cin>>num1>>num2;
        cout<<"The Power is : "<<pow(num1,num2)<<endl;
        break;

        case 7:
        cout << "Enter a number: ";
        cin>>num1;
        factorial = 1;
        for(long long i=1; i<=num1; ++i)
        {
            factorial *= i;
        }
        cout << "The factorial of " << num1 << " is: " << factorial << endl;
        break;

        case 8:
        cout << "Enter an angle in degrees: ";
        cin >> angle;
        cout << "The sine of " << angle << " degrees is: " << sin(angle * 3.141592653589793 / 180) << endl;
        break;

        case 9:
        cout << "Enter an angle in degrees: ";
        cin >> angle;
        cout << "The cosine of " << angle << " degrees is: " << cos(angle * 3.141592653589793 / 180)<< endl;
        break;

        case 10:
        cout << "Enter an angle in degrees: ";
        cin >> angle;
        cout << "The tangent of " << angle << " degrees is: " << tan(angle * 3.141592653589793 / 180) << endl;
        break;

        case 11:
        cout << "Enter an angle in degrees: ";
        cin >> angle;
        cout << "The sine of " << angle << " degrees is: " << sin(angle * 3.141592653589793 / 180) << endl;
        break;

        case 12:
        cout << "Enter an angle in degrees: ";
        cin >> angle;
        cout << "The cosine of " << angle << " degrees is: " << cos(angle * 3.141592653589793 / 180) << endl;
        break;

        case 13:
        cout << "Enter an angle in degrees: ";
        cin >> angle;
        cout << "The tangent of " << angle << " degrees is: " << tan(angle * 3.141592653589793 / 180) << endl;
        break;

        case 14:
        cout << "Enter a number: ";
        cin >> num1;
        if(num1 <= 0)
        {
            cout << "Error: Logarithm of a non-positive number is not defined." << endl;
        }
        else
        {
            cout << "The logarithm of " << num1 << " is: " << log(num1) << endl;
        }
        break;

        case 15:
        cout << "Enter the total marks and obtained marks: ";
        cin >> totalMarks >> obtainedMarks;
        percentage = (obtainedMarks / totalMarks) * 100;
        cout << "The percentage is: " << percentage << "%" << endl;
        break;

        case 16:
            cout << "Exiting the calculator." << endl;
            break;

        default:
            cout << "Invalid choice. Please select a valid option." << endl;
            break;

    }

}