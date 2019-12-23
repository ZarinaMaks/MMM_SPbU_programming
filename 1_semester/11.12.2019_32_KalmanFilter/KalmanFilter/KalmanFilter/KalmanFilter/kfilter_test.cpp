/*
 * Test for the KalmanFilter class with 1 DIMENSION projectile motion.
 */
#include <iostream>
#include <vector>
#include <Eigen/Dense>
using namespace std;
#include "kfilter.h"

int main(int argc, char* argv[]) {

    int n = 3; // - number of states
    int m = 1; // - number of measurements

    double dt = 1.0 / 30; // - time step

    Eigen::MatrixXd A(n, n); // - system dynamics matrix
    Eigen::MatrixXd C(m, n); // - output matrix
    Eigen::MatrixXd Q(n, n); // - process noise covariance
    Eigen::MatrixXd R(m, m); // - measurement noise covariance
    Eigen::MatrixXd P(n, n); // - estimate error covariance

    // discrete LTI projectile motion, measuring position only:
    A << 1, dt, 0, 0, 1, dt, 0, 0, 1;
    C << 1, 0, 0;

    // reasonable covariance matrices:
    Q << .05, .05, .0, .05, .05, .0, .0, .0, .0;
    R << 5;
    P << .1, .1, .1, .1, 10000, 10, .1, 10, 100;

    cout << "A: \n" << A << endl;
    cout << "C: \n" << C << endl;
    cout << "Q: \n" << Q << endl;
    cout << "R: \n" << R << endl;
    cout << "P: \n" << P << endl;

    KalmanFilter KF(dt, A, C, Q, R, P); // - construct the filter

    // - LIST OF NOISY POSITION MEASUREMENTS (y) - //
    vector<double> measurements = {
        1.50, 1.60, 1.00, 1.48, 1.79,
        1.74, 2.10, 2.14, 2.16, 2.21,
        2.57, 2.66, 2.51, 2.76, 2.88,
        2.65, 2.94, 2.82, 3.00, 3.19,
        2.83, 2.54, 2.58, 2.89, 2.01,
        2.03, 2.84, 2.69, 2.43, 2.23,
        2.30, 2.02, 1.94, 1.82, 1.52,
        1.86, 1.18, 1.10, 0.91, 0.69,
        0.96, 0.48, -0.15, -0.28, -0.60
    };
    // -- //

    // Best guess of initial states:
    Eigen::VectorXd x0(n);
    double t = 0;
    double t0 = t;
    x0 << measurements[0], 0, -9.81;
    KF.init(t, x0);

    //put measurements into filter, output estimated states:
    Eigen::VectorXd y(m);
    cout << "t = " << t << ", " << "x_hat[0]: " << KF.state().transpose() << endl;
    for (int i = 0; i < measurements.size(); i++) {
        t += dt;
        y << measurements[i];
        KF.update(y);
        cout << "t = " << t << ", " << "y[" << i << "] = " << y.transpose()
            << "; " << "x_hat[" << i << "] = " << KF.state().transpose() << endl;
    }
    return 0;
}