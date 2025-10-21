# Flower Pattern Using Python
# Author: Yash Sengar
# Description: This program prints a flower-like pattern using the '*' symbol.

import turtle

# Set up the screen
screen = turtle.Screen()
screen.bgcolor("black")

# Create the turtle
pen = turtle.Turtle()
pen.color("yellow")
pen.speed(10)

# Draw the flower
for i in range(36):
    pen.circle(100)
    pen.right(10)

# Draw the stem
pen.right(90)
pen.color("green")
pen.pensize(10)
pen.forward(300)

# Hide the turtle
pen.hideturtle()

# Keep the window open
turtle.done()
