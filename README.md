# Explosion Test

## Intro

This program is written to do simple boom tests, and it includes four kinds of tests, which are "Common" for common air composition, "Coward" based on ["Coward Triangle"](https://github.com/TyeYeah/ExplosionTestQTDemo/blob/master/Coward.jpg), "Le chart" based on ["Le Chatelier"](https://github.com/TyeYeah/ExplosionTestQTDemo/blob/master/Le%20Chatelier.jpg), and "Kukuczka" using ["Kukuczka' Method"](https://github.com/TyeYeah/ExplosionTestQTDemo/blob/master/Kukuczka.png) to check explosibility.

Those above are familiar to students who studying Combustion Science, and this can be a roughcast for them to build their personal tools to calculate explosibility.

## Coward Triangle

Lots of methods have been developed to determine the explosibility of the mixture gas in the sealed area for a long time. One of these methods is the Coward explosive triangle method which was published by Coward in 1952. Because of its easiness and high efficiency to determine the explosibility of the mixture gas, it gradually becomes a very popular tool for mining engineers and rescue team members in the mining industry.

You can input composition of N2, H2, and O2 to see it is explosive or not.

The graph is down here, and we can see in the red triangle surrounded by 0% N2, 94% H2, and 4% H2, it is explosive.

!["Coward Triangle"](https://raw.githubusercontent.com/TyeYeah/ExplosionTestQTDemo/master/Coward.jpg)

## Le Chatelier' Principle

[Here](https://en.wikipedia.org/wiki/Le_Chatelier%27s_principle) is the introduction

You can input Ratio of two gas and the real value (percent flammable gas plus diluent).

In this Le chart, If data is inside the relevent curve, then it explodes.

!["Le Chatelier"](https://raw.githubusercontent.com/TyeYeah/ExplosionTestQTDemo/master/Le%20Chatelier.jpg)

## Kukuczka's Method

Program is made in the principle of Kukuczka s method for calculation of the inflammability limit of mine gases. After calculation and verification it is found that this method is not in conformity with LeChatelier s law.

Input CO2, CH4, C2H2, C2H4, C2H6, CO, N2, H2, and O2 to see its explosibility.

It is a method to determine the mine gas explosibility.

!["Kukuczka"](https://raw.githubusercontent.com/TyeYeah/ExplosionTestQTDemo/master/Kukuczka.png)

## Features

This is a Demo and an attemption to code with QT, but few efforts on using signal slot, which means many aspects need to be improved.
