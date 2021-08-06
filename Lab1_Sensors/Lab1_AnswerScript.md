<img src="https://github.com/ee209-2020class/ee209-2020class.github.io/blob/master/ExtraInfo/logo.png">

# Answer Sheet - Lab 1

## Part 1: Revising Basics

Q 1.1: Determine the load current (IL), load voltage (VL), and power delivered to the load (PL).

> IL: 0.5A

> VL: 7V

> PL: 3.5W

Q 1.2: After predicting how the circuit should behave theoretically, you should now simulate the circuit in LTspice and validate your theoretical analysis. Use the LTspice model provided to you (labelled Part 1A).

| Parameter             | Theoretical Value    | Simulated Value      |
| ----------------------|----------------------|----------------------|
| IL                    |         0.5          |           0.5        |
| VL                    |          7           |            7         |
| PL                    |         3.5          |           3.5        |

> Comments (state if results match/differ): the results are the same dude to the simplicity of the circuit and lack of non linear or transient components.

Q 1.3: What would be an appropriate “Maximum Timestep” and “Stop Time” to be used for this simulation?

> Time Step (assuming 1/20th of the period of 500 Hz): 1/500 /20 = 0.1 ms

> Stop Time (assuming we’d like to capture 200 cycles): 1/500 * 200 = 0.4 Seconds

Q 1.4: Calculate the theoretical load current (IL(RMS)), load voltage (VL(RMS)), peak instantaneous power (PL(t)), and average power delivered by the source (Pin) for the circuits shown above. Simulate these circuits in LTspice using the models provided (labelled Part 1B-1D) and compare with the theoretical results.

> Circuit with Resistor

| Parameter             | Theoretical Value    | Simulated Value      |
| ----------------------|----------------------|----------------------|
| IL(rms)               |    1.12              |      1.12            |
| VL(rms)               |    14                |      14              |
| Peak PL(t)            |    15.68             |      15.68           |
| Pin                   |    15.68             |      15.68           |

> Circuit with Inductor

| Parameter             | Theoretical Value    | Simulated Value      |
| ----------------------|----------------------|----------------------|
| IL(rms)               |                      |      1.2             |
| VL(rms)               |                      |      14              |
| Peak PL(t)            |                      |      16.8            |
| Pin                   |                      |      16.8 ?          |

> Circuit with Capacitor

| Parameter             | Theoretical Value    | Simulated Value      |
| ----------------------|----------------------|----------------------|
| IL(rms)               |                      |       1.17           |
| VL(rms)               |                      |       15.7           |
| Peak PL(t)            |                      |       18.4           |
| Pin                   |                      |       18.4 ?         |

Q 1.5: How can we minimise the granularity of simulation points and improve the accuracy? What would be a drawback of doing so?

> we can improve the accuracy by decreasing the step size. this will record data at closer intervals and give us a smoother curve, but it will increase the simulation time and resource usage. we can mitigate this downside by decreasing the total simulation time as well, so that we end up getting a very accurate simulation of a small area of data we want to investigate.

Q 1.6: Lets add a 0.2 Ohm resistor in series with the inductor and a 790 Ohm resistor in parallel with the capacitor to help the two circuits reach steady-state conditions faster. What is the time-constant of each circuit? Will your simulation reach steady-state well before the “Stop Time” you have defined? (i.e. is the “Stop Time” larger than 5 times the time constant?)

> Time constant of circuit with 4mH inductor: TC = L / R = 0.004/0.2 = 0.02

> Time constant of circuit with 25.3uF capacitor: TC = R * C = 790 * 25.3 * 10^-6 = 0.019987

> Would simulation reach steady-state: 0.02 * 5 = 0.1 < 0.4 So yes, the simulation would reach steady state.

Q 1.7: Modify the simulation as per Q1.6 and run it. Compare the simulation results you obtained from the modified circuits to show that they somewhat agree with the theoretical predictions. You can further improve the accuracy of your simulations by reducing the “Maximum Timestep” and/or reducing the impact on the circuit due to the resistive element you added. However, this will be at the expense of simulation time.

> Circuit with Inductor

| Parameter             | Simulated Value      |
| ----------------------|----------------------|
| IL(rms)               |   1.06A              |
| VL(rms)               |   14V                |
| Peak PL(t)            |   14.84              |
| Pin                   |   14.84              |

> Circuit with Capacitor

| Parameter             | Simulated Value      |
| ----------------------|----------------------|
| IL(rms)               |  1.11A               |
| VL(rms)               |  13.44V              |
| Peak PL(t)            |  14.9                |
| Pin                   |  14.9                |

> Comments (state observation when experimenting with “Maximum Timestep”): The extra resistor does well to rapidly get the circuit to a steady state. because of this efficency, lots of resources are wasted on simulating the same strady state. so in the future we could add the resistor and also decrease the simulation record time closer to 5 time constants.

## Part 2: Modelling Your AC Load

Q 2.1: As stated in your design specifications, the AC voltage supplied by the power supply across the AC load is going to be between 12.6Vrms and 15.4Vrms. The AC load is going to be set to draw 2.5VA-7.5VA regardless of the AC voltage supplied to it. What is the maximum and minimum current you expect to measure? What is the maximum and minimum AC voltage you expect to measure?

> Maximum RMS load voltage: 4.46

> Minimum RMS load voltage: 0.41

> Maximum RMS load current: 6.16

> Minimum RMS load current: 1.68

Q 2.2: Assume that the viper on the variable resistor is set somewhat closer to the lowest resistance position, and therefore RL is 25 Ohm. We are also assuming that L is 4mH and Vac is 14Vrms in this specific example. Note that these numbers are chosen as an example load setting we may test your circuit at. Using circuit theory, determine the RMS load current as well as the real, reactive, and apparent power consumed by the load. Verify answers using the LTspice model provided (labelled Part 2).

| Parameter             | Theoretical Value    | Simulated Value      |
| ----------------------|----------------------|----------------------|
| Load current IL(rms)  |                      |                      |
| Real power (W)        |                      |                      |
| Reactive power (VAR)  |                      |                      |
| Apparent power (VA)   |                      |                      |

> Comment (state if results match/differ and why):

Q 2.3: Similarly, calculate and simulate the RMS load current, real, reactive, and apparent power if the viper position is changed to increase RL to 75 Ohm (i.e. closer to the highest resistance position)? Again, these numbers are chosen as an example setting we may test your circuit at (note that L is 4mH and Vac is 14Vrms).

| Parameter             | Theoretical Value    | Simulated Value      |
| ----------------------|----------------------|----------------------|
| Load current IL(rms)  |                      |                      |
| Real power (W)        |                      |                      |
| Reactive power (VAR)  |                      |                      |
| Apparent power (VA)   |                      |                      |

> Comment (state if results match/differ and why):

## Part 3: Sensing AC Load Current

Q 3.1: Determine the value of the shunt resistor suitable to measure the current flowing through the AC load used in your project. Note that you have already calculated the minimum and maximum currents to be measured in Q2.1. Limit the maximum power dissipation in the shunt resistor to 200mW.

> Shunt Resistor (Rs):

Q 3.2: Using the simulation model given (labelled Part 3 & 4), verify that you have calculated the correct shunt resistor value in Q3.1. You can validate the design by changing load resistance/supply voltage to vary the VA drawn by the AC load, while keeping it within 7.5VA to 2.5VA and observing peak amplitude of sensed voltage (Vis(pk)) as well as the power dissipated in the shunt resistor (Pis).

> Summarise key findings (theoretical vs simulated) in table below. Here we are analysing circuit under 3 possible scenarios including the two extreme cases (i.e. minimum and maximum load current). We are assuming that L is exactly 4mH and RL is changed to simulate varying load conditions.

| Source VA  | Vac(rms) | RL       | IL(rms)  | Vis(pk) Theo | Vis(pk) Sim  | Pis Theo | Pis Sim  |
| -----------|----------|----------|----------|--------------|--------------|----------|----------|
| 7.5VA      | 12.6V    |          |          |              |              |          |          |
| 7.5VA      | 15.4V    |          |          |              |              |          |          |
| 2.5VA      | 15.4V    |          |          |              |              |          |          |

> Comments (state if Pis is kept below 200mW under all conditions):

Q 3.3: Using table below, compare the advantages and disadvantages of using a bigger vs a smaller shunt resistor than the one in Q3.1? Based on this comparison, what specific value will you use as the shunt resistor in your project? Will you use the value calculated in Q3.1 or a different value? Justify your selection.

| Parameter             | Bigger Rs Value      | Smaller Rs Value     |
| ----------------------|----------------------|----------------------|
| SNR                   |                      |                      |
| Dissipation (Pis)     |                      |                      |
| Size                  |                      |                      |
| Cost                  |                      |                      |

> Shunt resistor (Rs) to be used in your design:

> Justification:

## Part 4: Sensing AC Source Voltage

Q 4.1: Determine the values of the voltage divider resistors suitable for measuring the input voltage supplied by the AC source. Note that you have already calculated the minimum and maximum input voltages to be measured in Q2.1. The voltage divider should step down the maximum load voltage to about 2Vpk-pk so that it can be processed by the signal conditioning circuit and fed to an ADC channel of the microcontroller. Make sure to pick E12 resistor values from the ROYALOHM MF006JJ metal film resistor series.

> Voltage divider resistors (Ra and Rb):

Q 4.2: Using the simulation model given (labelled Part 3 & 4), verify that you have calculated the correct voltage divider resistor values in Q4.1. You can validate the design by changing the load resistance/supply voltage to vary the VA drawn by the AC load, while keeping it within 7.5VA to 2.5VA and observing peak amplitude of sensed voltage (Vvs). It is also good to check the total power dissipated in the resistors (Pvs).

> Summarise the key findings (theoretical vs simulated) in table below. Here we are analysing the circuit under 3 possible scenarios including the two extreme cases (i.e. minimum and maximum input voltage). We are assuming that L is exactly 4mH and RL is changed to simulate varying load conditions.

| Source VA  | Vac(rms) | RL       | IL(rms)  | Vvs(pk) Theo | Vvs(pk) Sim  | Pvs Theo | Pvs Sim  |
| -----------|----------|----------|----------|--------------|--------------|----------|----------|
| 7.5VA      | 12.6V    |          |          |              |              |          |          |
| 7.5VA      | 15.4V    |          |          |              |              |          |          |
| 2.5VA      | 15.4V    |          |          |              |              |          |          |

> Comments (state if 2Vpk-pk is met and Pvs is acceptably low):

Q 4.3: Using table below, compare the advantages and disadvantages of using resistors for your voltage divider in the Ohms vs Kilo-Ohms vs Mega-Ohms range. Based on this comparison, what specific values will you use in the voltage divider? Will you use the values calculated in Q4.1 or different values? Justify your selection.

| Parameter             | Ohms        | Kilo-Ohms   | Mega-Ohms   |
| ----------------------|-------------|-------------|-------------|
| SNR                   |             |             |             |
| Dissipation (Pis)     |             |             |             |
| Sensitivity           |             |             |             |

> Voltage divider resistors (Ra and Rb) to be used in your design:

> Justification:

## Optional Task: Practical Thoughts

Q O.1: Assume that you have decided to use two 1 Ohm ROYALOHM MF006JJ series metal film resistors in parallel as the shunt resistor (Rs). As shown in the datasheet, the resistors have a tolerance of +/-5% and a temperature coefficient of +/-200ppm/°C (measured from 20°C). What are the worst-case minimum and maximum values of your current shunt? Note that your energy monitor will be designed to operate in a 10°C to 40°C ambient temperature. State all assumptions you made. Also, comment on the expected measurement accuracy based on the minimum and maximum shunt resistance values calculated.

> Minimum Rs:                   (observed when 					)

> Maximum Rs:                   (observed when 					)

> Assumptions:

> Expected Accuracy:
