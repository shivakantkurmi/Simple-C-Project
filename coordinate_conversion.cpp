#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

// Constants
const double PI = 3.141592653589793;

// Conversion functions for 2D Cartesian <-> Polar
void cartesianToPolar(double x, double y, double& r, double& theta) {
    r = sqrt(x * x + y * y);
    theta = atan2(y, x);  // Theta in radians
}

void polarToCartesian(double r, double theta, double& x, double& y) {
    x = r * cos(theta);
    y = r * sin(theta);
}

// Conversion functions for 3D Cartesian <-> Spherical
void cartesianToSpherical(double x, double y, double z, double& r, double& theta, double& phi) {
    r = sqrt(x * x + y * y + z * z);
    theta = atan2(sqrt(x * x + y * y), z); // Elevation angle
    phi = atan2(y, x); // Azimuthal angle
}

void sphericalToCartesian(double r, double theta, double phi, double& x, double& y, double& z) {
    x = r * sin(theta) * cos(phi);
    y = r * sin(theta) * sin(phi);
    z = r * cos(theta);
}

// Conversion functions for 3D Cartesian <-> Cylindrical
void cartesianToCylindrical(double x, double y, double z, double& r, double& phi, double& z_cyl) {
    r = sqrt(x * x + y * y);
    phi = atan2(y, x);  // Azimuthal angle
    z_cyl = z;
}

void cylindricalToCartesian(double r, double phi, double z_cyl, double& x, double& y, double& z) {
    x = r * cos(phi);
    y = r * sin(phi);
    z = z_cyl;
}

// Convert Polar to Spherical
void polarToSpherical(double r_polar, double theta_polar, double& r_spherical, double& theta_spherical, double& phi_spherical) {
    r_spherical = r_polar;  // The radius stays the same
    theta_spherical = PI / 2;  // The elevation angle is 90 degrees (π/2 radians) for 2D polar
    phi_spherical = theta_polar;  // Azimuthal angle is the same as polar angle
}

// Convert Spherical to Polar
void sphericalToPolar(double r_spherical, double theta_spherical, double phi_spherical, double& r_polar, double& theta_polar) {
    r_polar = r_spherical * sin(theta_spherical);  // Project onto the XY-plane
    theta_polar = phi_spherical;  // The azimuthal angle becomes the polar angle
}

// Convert Polar to Cylindrical
void polarToCylindrical(double r_polar, double theta_polar, double& r_cylindrical, double& phi_cylindrical, double& z_cylindrical) {
    r_cylindrical = r_polar;
    phi_cylindrical = theta_polar;
    z_cylindrical = 0;  // Since it's 2D, z is 0
}

// Convert Cylindrical to Polar
void cylindricalToPolar(double r_cylindrical, double phi_cylindrical, double z_cylindrical, double& r_polar, double& theta_polar) {
    r_polar = r_cylindrical;
    theta_polar = phi_cylindrical;  // Azimuthal angle in cylindrical is the same as polar angle
}

// Convert Spherical to Cylindrical
void sphericalToCylindrical(double r_spherical, double theta_spherical, double phi_spherical, double& r_cylindrical, double& phi_cylindrical, double& z_cylindrical) {
    r_cylindrical = r_spherical * sin(theta_spherical);  // Project onto the XY-plane
    phi_cylindrical = phi_spherical;  // Azimuthal angle is the same
    z_cylindrical = r_spherical * cos(theta_spherical);  // Height (z) from spherical to cylindrical
}

// Convert Cylindrical to Spherical
void cylindricalToSpherical(double r_cylindrical, double phi_cylindrical, double z_cylindrical, double& r_spherical, double& theta_spherical, double& phi_spherical) {
    r_spherical = sqrt(r_cylindrical * r_cylindrical + z_cylindrical * z_cylindrical);  // Radius in spherical
    theta_spherical = atan2(r_cylindrical, z_cylindrical);  // Elevation angle
    phi_spherical = phi_cylindrical;  // Azimuthal angle remains the same
}

// Menu for conversion options
void menu() {
    cout<<"Name : Shivakant Kurmi \n";
    cout<<"Reg. No.: 23BCG10140 \n";
    cout << "Choose a conversion option:\n";
    cout << "1. Convert 2D Cartesian to Polar\n";
    cout << "2. Convert 2D Polar to Cartesian\n";
    cout << "3. Convert 3D Cartesian to Spherical\n";
    cout << "4. Convert 3D Spherical to Cartesian\n";
    cout << "5. Convert 3D Cartesian to Cylindrical\n";
    cout << "6. Convert 3D Cylindrical to Cartesian\n";
    cout << "7. Convert Polar to Spherical\n";
    cout << "8. Convert Spherical to Polar\n";
    cout << "9. Convert Polar to Cylindrical\n";
    cout << "10. Convert Cylindrical to Polar\n";
    cout << "11. Convert Spherical to Cylindrical\n";
    cout << "12. Convert Cylindrical to Spherical\n";
    cout << "13. Exit\n";
}

int main() {
    int choice;
    do {
       
        menu();
        cout << "Enter your choice: ";
        cin >> choice;
       
        if (choice == 1) {
            // Convert 2D Cartesian to Polar
            double x, y, r, theta;
            cout << "Enter x and y: ";
            cin >> x >> y;
            cartesianToPolar(x, y, r, theta);
            cout << "Polar coordinates: r = " << r << ", theta (radians) = " << theta << "\n";

        } else if (choice == 2) {
            // Convert 2D Polar to Cartesian
            double r, theta, x, y;
            cout << "Enter r and theta (in radians): ";
            cin >> r >> theta;
            polarToCartesian(r, theta, x, y);
            cout << "Cartesian coordinates: x = " << x << ", y = " << y << "\n";

        } else if (choice == 3) {
            // Convert 3D Cartesian to Spherical
            double x, y, z, r, theta, phi;
            cout << "Enter x, y, and z: ";
            cin >> x >> y >> z;
            cartesianToSpherical(x, y, z, r, theta, phi);
            cout << "Spherical coordinates: r = " << r << ", theta = " << theta << ", phi = " << phi << "\n";

        } else if (choice == 4) {
            // Convert 3D Spherical to Cartesian
            double r, theta, phi, x, y, z;
            cout << "Enter r, theta, and phi (in radians): ";
            cin >> r >> theta >> phi;
            sphericalToCartesian(r, theta, phi, x, y, z);
            cout << "Cartesian coordinates: x = " << x << ", y = " << y << ", z = " << z << "\n";

        } else if (choice == 5) {
            // Convert 3D Cartesian to Cylindrical
            double x, y, z, r, phi, z_cyl;
            cout << "Enter x, y, and z: ";
            cin >> x >> y >> z;
            cartesianToCylindrical(x, y, z, r, phi, z_cyl);
            cout << "Cylindrical coordinates: r = " << r << ", phi = " << phi << ", z = " << z_cyl << "\n";

        } else if (choice == 6) {
            // Convert 3D Cylindrical to Cartesian
            double r, phi, z_cyl, x, y, z;
            cout << "Enter r, phi, and z: ";
            cin >> r >> phi >> z_cyl;
            cylindricalToCartesian(r, phi, z_cyl, x, y, z);
            cout << "Cartesian coordinates: x = " << x << ", y = " << y << ", z = " << z << "\n";

        } else if (choice == 7) {
            // Convert Polar to Spherical
            double r, theta, r_spherical, theta_spherical, phi_spherical;
            cout << "Enter r and theta (in radians): ";
            cin >> r >> theta;
            polarToSpherical(r, theta, r_spherical, theta_spherical, phi_spherical);
            cout << "Spherical coordinates: r = " << r_spherical << ", theta = " << theta_spherical << ", phi = " << phi_spherical << "\n";

        } else if (choice == 8) {
            // Convert Spherical to Polar
            double r, theta, phi, r_polar, theta_polar;
            cout << "Enter r, theta, and phi (in radians): ";
            cin >> r >> theta >> phi;
            sphericalToPolar(r, theta, phi, r_polar, theta_polar);
            cout << "Polar coordinates: r = " << r_polar << ", theta (radians) = " << theta_polar << "\n";

        } else if (choice == 9) {
            // Convert Polar to Cylindrical
            double r, theta, r_cylindrical, phi_cylindrical, z_cylindrical;
            cout << "Enter r and theta (in radians): ";
            cin >> r >> theta;
            polarToCylindrical(r, theta, r_cylindrical, phi_cylindrical, z_cylindrical);
            cout << "Cylindrical coordinates: r = " << r_cylindrical << ", phi = " << phi_cylindrical << ", z = " << z_cylindrical << "\n";

        } else if (choice == 10) {
            // Convert Cylindrical to Polar
            double r_cylindrical, phi_cylindrical, z_cylindrical, r_polar, theta_polar;
            cout << "Enter r, phi, and z: ";
            cin >> r_cylindrical >> phi_cylindrical >> z_cylindrical;
            cylindricalToPolar(r_cylindrical, phi_cylindrical, z_cylindrical, r_polar, theta_polar);
            cout << "Polar coordinates: r = " << r_polar << ", theta (radians) = " << theta_polar << "\n";

        } else if (choice == 11) {
            // Convert Spherical to Cylindrical
            double r, theta, phi, r_cylindrical, phi_cylindrical, z_cylindrical;
            cout << "Enter r, theta, and phi (in radians): ";
            cin >> r >> theta >> phi;
            sphericalToCylindrical(r, theta, phi, r_cylindrical, phi_cylindrical, z_cylindrical);
            cout << "Cylindrical coordinates: r = " << r_cylindrical << ", phi = " << phi_cylindrical << ", z = " << z_cylindrical << "\n";

        } else if (choice == 12) {
            // Convert Cylindrical to Spherical
            double r_cylindrical, phi_cylindrical, z_cylindrical, r_spherical, theta_spherical, phi_spherical;
            cout << "Enter r, phi, and z: ";
            cin >> r_cylindrical >> phi_cylindrical >> z_cylindrical;
            cylindricalToSpherical(r_cylindrical, phi_cylindrical, z_cylindrical, r_spherical, theta_spherical, phi_spherical);
            cout << "Spherical coordinates: r = " << r_spherical << ", theta = " << theta_spherical << ", phi = " << phi_spherical << "\n";

        }

    } while (choice != 13);

    return 0;
}
