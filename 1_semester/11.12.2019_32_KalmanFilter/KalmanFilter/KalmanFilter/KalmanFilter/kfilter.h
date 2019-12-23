#include <Eigen/Dense>
#pragma once

class KalmanFilter {

public:
    //Creating a Kalman filter with the specified matrixes:
    KalmanFilter(
        double dt,
        const Eigen::MatrixXd& A, // - System dynamics matrix
        const Eigen::MatrixXd& C, // - Output matrix
        const Eigen::MatrixXd& Q, // - Process noise covariance
        const Eigen::MatrixXd& R, // - Measurement noise covariance
        const Eigen::MatrixXd& P  // - Estimate error covariance
    );
    KalmanFilter(); // - creating a blank estimator
    void init(); // - initializing the filter with initial states (t0, x0) as zeroes
    void init(double t0, const Eigen::VectorXd& x0); // - initializing the filter with a guess for initial states
    void update(const Eigen::VectorXd& y); // - updating the estimated state based on measured values. The time step is assumed to remain constant
    void update(const Eigen::VectorXd& y, double dt, const Eigen::MatrixXd A); // - update the estimated state based on measured values, using the given time step and dynamics matrix

    // - RETURNING THE CURRENT STATE AND TIME - //
    Eigen::VectorXd state() { return x_hat; };
    double time() { return t; };
    // -- //

private:
    Eigen::MatrixXd A, C, Q, R, P, K, P0; // - matrice for computation
    int m, n; // - system dimensions
    double t0, t; // - initial(starting) and current time
    double dt; // - discrete time step
    bool initialized; // - is the filter initialized?
    Eigen::MatrixXd I; // - n-size identity
    Eigen::VectorXd x_hat, x_hat_new; // - estimated states
};