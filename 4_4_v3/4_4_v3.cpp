#include "vector.h"

using namespace std;

double scalarProduct(const Vector& X, const Vector& Y) {
    if (X.getSize() != Y.getSize()) {
        cerr << "Error: Vector dimensions are different" << endl;
        return 0.0;
    }
    double sum = 0.0;
    for (int i = 0; i < X.getSize(); i++) {
        sum += X.getElement(i) * Y.getElement(i);
    }
    
    return sum;
}

int main() {
    int N;
    cout << "Enter vector size: ";
    cin >> N;

    Vector X(N);
    cout << "Enter vector X elements: ";
    X.input();

    Vector Y(N);
    cout << "Enter vector Y elements: ";
    Y.input();

    int choice;
    do {
        cout << "Choose an operation:" << endl;
        cout << "1. Add vectors" << endl;
        cout << "2. Subtract vectors" << endl;
        cout << "3. Multiply vectors" << endl;
        cout << "4. Divide vectors" << endl;
        cout << "5. Scalar product" << endl;
        cout << "6. Add scalar to vector X" << endl;
        cout << "7. Subtract scalar from vector X" << endl;
        cout << "8. Multiply vector X by scalar" << endl;
        cout << "9. Divide vector X by scalar" << endl;
        cout << "10. Fill vector X with random values" << endl;
        cout << "0. Exit" << endl;
        cout << "Your choice?: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Vector Z = X.add(Y);
            cout << "Vector Z (X + Y): ";
            Z.print();
            break;
        }
        case 2: {
            Vector Z = X.subtract(Y);
            cout << "Vector Z (X - Y): ";
            Z.print();
            break;
        }
        case 3: {
            Vector Z = X.multiply(Y);
            cout << "Vector Z (X * Y): ";
            Z.print();
            break;
        }
        case 4: {
            Vector Z = X.divide(Y);
            cout << "Vector Z (X / Y): ";
            Z.print();
            break;
        }
        case 5: {
            double scalar_prod = scalarProduct(X, Y);
            cout << "Scalar product of X and Y: " << scalar_prod << endl;

            Vector z(X.getSize());
            for (int i = 0; i < X.getSize(); i++) {
                z.setElement(i, X.getElement(i) + scalar_prod);
            }
            cout << "Vector Z = x[i] + k: ";
            z.print();
            break;
        }
        case 6: {
            double scalar;
            cout << "Enter scalar value: ";
            cin >> scalar;
            X.addScalar(scalar);
            cout << "Vector X after adding scalar: ";
            X.print();
            break;
        }
        case 7: {
            double scalar;
            cout << "Enter scalar value: ";
            cin >> scalar;
            X.subtractScalar(scalar);
            cout << "Vector X after subtracting scalar: ";
            X.print();
            break;
        }
        case 8: {
            double scalar;
            cout << "Enter scalar value: ";
            cin >> scalar;
            X.multiplyScalar(scalar);
            cout << "Vector X after multiplying by scalar: ";
            X.print();
            break;
        }
        case 9: {
            double scalar;
            cout << "Enter scalar value: ";
            cin >> scalar;
            X.divideScalar(scalar);
            cout << "Vector X after dividing by scalar: ";
            X.print();
            break;
        }
        case 10: {
            X.fillRandom();
            cout << "Vector X after filling with random values: ";
            X.print();
            break;
        }
        case 0:
            cout << "Done" << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    return 0;
}
