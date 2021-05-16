# -*- coding: utf-8 -*-

# -- Sheet --

#Справедлива теорема аппроксимации: 
#Искусственная нейронная сеть прямой связи 
#(англ. feed-forward; в которых связи не образуют циклов) 
#с одним скрытым слоем может аппроксимировать любую непрерывную 
#функцию многих переменных с любой точностью.
import tensorflow as tf
import matplotlib.pyplot as plt
import numpy as np
import math

x_min, x_max = 0, 10

test_data_size = 1000 # amount of data for learning
iterations = 10000 # amount of iterations
learn_rate = 0.01 # re-learning coefficient
hiddenSize = 10 # size of hidden layer

def random_test_values():
    train_x = []
    train_y = []
    for _ in range(test_data_size):
        x = x_min+np.random.rand()*(x_max-x_min)
        y = math.sin(x) # studied function
        train_x.append([x])
        train_y.append([y])

    return np.array(train_x), np.array(train_y)

x = tf.placeholder(tf.float32, [None, 1], name="x") #function arguments
y = tf.placeholder(tf.float32, [None, 1], name="y") #function values

# Hidden layer:
nn = tf.layers.dense(x, hiddenSize,
                     activation=tf.nn.sigmoid,
                     kernel_initializer=tf.initializers.ones(),
                     bias_initializer=tf.initializers.random_uniform(minval=-x_max, maxval=-x_min),
                     name="hidden")

# Final layer:
model = tf.layers.dense(nn, 1,
                        activation=None,
                        name="output")

cost = tf.losses.mean_squared_error(y, model)
train = tf.train.GradientDescentOptimizer(learn_rate).minimize(cost)
init = tf.initializers.global_variables()

with tf.Session() as session:
    session.run(init)
    for _ in range(iterations):

        train_dataset, train_values = random_test_values()

        session.run(train, feed_dict={
            x: train_dataset,
            y: train_values
        })

        if(_ % 1000 == 999):
            print("cost = {}".format(session.run(cost, feed_dict={
                x: train_dataset,
                y: train_values
            })))

    train_dataset, train_values = random_test_values()

    train_values1 = session.run(model, feed_dict={
        x: train_dataset,
    })

    plt.plot(train_dataset, train_values, "bo", train_dataset, train_values1, "ro")
    plt.show()

    with tf.variable_scope("hidden", reuse=True):
        w = tf.get_variable("kernel")
        b = tf.get_variable("bias")
        print("hidden:")
        print("kernel=", w.eval())
        print("bias = ", b.eval())
    
    with tf.variable_scope("output", reuse=True):
        w = tf.get_variable("kernel")
        b = tf.get_variable("bias")
        print("output:")
        print("kernel=", w.eval())
        print("bias = ", b.eval())

