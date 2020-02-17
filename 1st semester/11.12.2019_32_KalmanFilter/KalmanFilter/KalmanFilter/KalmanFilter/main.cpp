/*
 * Организовать фильтрацию зашумленных данных в задаче определения позиции объекта.
 * Постановка задачи в статье на хабре: https://habr.com/ru/post/166693/
 * Kalman filters are used for some time now, in aeronautics, robot vision and robotics in general.
 * It is useful to estimate a state vector and correct the estimation by using measures taken from sensors.
 * Its main uses is for tracking or data fusion.
 * It implements the algorithm directly.
 * This is a basic KalmanFilter implementation in C++ using the Eigen (library version: 3.2.10)
 * http://eigen.tuxfamily.org/index.php?title=Main_Page
 */
#include <iostream>
#include <stdexcept>
#include "kfilter.h"

KalmanFilter::KalmanFilter(
    double dt,
    const Eigen::MatrixXd& A,
    const Eigen::MatrixXd& C,
    const Eigen::MatrixXd& Q,
    const Eigen::MatrixXd& R,
    const Eigen::MatrixXd& P)
    : A(A), C(C), Q(Q), R(R), P0(P),
    m(C.rows()), n(A.rows()), dt(dt), initialized(false),
    I(n, n), x_hat(n), x_hat_new(n)
{
    I.setIdentity();
}

KalmanFilter::KalmanFilter() {}

void KalmanFilter::init(double t0, const Eigen::VectorXd& x0) {
    x_hat = x0;
    P = P0;
    this->t0 = t0;
    t = t0;
    initialized = true;
}

void KalmanFilter::init() {
    x_hat.setZero();
    P = P0;
    t0 = 0;
    t = t0;
    initialized = true;
}

void KalmanFilter::update(const Eigen::VectorXd& y) {

    if (!initialized)
        throw std::runtime_error("Filter is not initialized!");

    x_hat_new = A * x_hat;
    P = A * P * A.transpose() + Q;
    K = P * C.transpose() * (C * P * C.transpose() + R).inverse();
    x_hat_new += K * (y - C * x_hat_new);
    P = (I - K * C) * P;
    x_hat = x_hat_new;

    t += dt;
}

void KalmanFilter::update(const Eigen::VectorXd& y, double dt, const Eigen::MatrixXd A) {

    this->A = A;
    this->dt = dt;
    update(y);
}
