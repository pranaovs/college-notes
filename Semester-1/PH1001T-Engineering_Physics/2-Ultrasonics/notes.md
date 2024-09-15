# Ultrasonics

---

title: Ultrasonics Notes - Engineering Physics Semester 1

author: Pranaov S

lecturer: N P Rajesh

code: PH1001T

marks: 5

---

<!--toc:start-->
- [Ultrasonics](#ultrasonics)
  - [Syllabus](#syllabus)
  - [Introduction](#introduction)
    - [Properties of Ultrasonic Waves](#properties-of-ultrasonic-waves)
  - [Production of Ultrasonic Waves](#production-of-ultrasonic-waves)
    - [Magnetostriction generator](#magnetostriction-generator)
      - [Advantages](#advantages)
      - [Disadvantages](#disadvantages)
    - [Piezoelectric generator](#piezoelectric-generator)
      - [Advantages](#advantages)
  - [Detection](#detection)
    - [Piezoelectric Detection](#piezoelectric-detection)
  - [Ultrasonic Testing](#ultrasonic-testing)
    - [Non-destructive Testing](#non-destructive-testing)
      - [Normal Beam Pulse-Echo Testing](#normal-beam-pulse-echo-testing)
      - [Normal beam pulse through-transmission testing](#normal-beam-pulse-through-transmission-testing)
<!--toc:end-->

## Syllabus

Production - Magnetostriction and Piezoelectric methods

Detection – Piezoelectric, Acoustic grating

Non Destructive Testing

Pulse echo system

Reflection and transmission modes

Modes of data presentation - A, B and C scan displays

Sonogram

## Introduction

Human ears can hear sound waves ranging from 20 Hz to 20 kHz.
Sounds above 20 kHz are called ultrasonic sounds.

### Properties of Ultrasonic Waves

1. The speed of propagation of ultrasonic waves depend upon their frequency. It increases with increase in frequency.
2. The wavelength of the waves are very small and the waves exhibit negligible diffraction effects.
3. The can travel over long distances as a highly direction beam and without much loss of energy.
4. The are highly energetic. Intensities are up to $10~kW/m^{2}$. Normally, 1 to 2 $kW/m^{2}$ intensities are used.
5. They produce cavitation effects in liquids.

## Production of Ultrasonic Waves

### Magnetostriction generator

> **Magnetostriction effect:**
> When a rod of ferromagnetic material (such as iron or nickel) is placed in a magnetic field parallel to its length,
> the rod experiences a change in length.
> This change is independent of the direction of the magnetic field and is only dependent on the magnitude of the field and the nature of the material.
> This phenomenon is known as Magnetostriction effect.
>
> Nickel exhibits a large magnetostriction effect compared to other ferromagnetic materials.

A simple method of producing longitudinal vibrations is to apply an AC magnetic field parallel to the axis of the rod of a ferromagnetic material.
An AC magnetic field is produced by wounding coil of wire around the rod and by passing AC current through it.
Let the frequency of the AC current by $f$.
The rod changes in length for once every half-cycle.
If the rod is not magnetized initially, the change in length may either be elongation or contraction.
Normally, the amplitude of vibrations are small,
but when the frequency of the alternating fields is equal to the natural frequency of the rod,
resonance occurs and the vibrations will be considerably larger.
Further, if the frequency of the alternating fields lie in ultrasonic range,
and ultrasound of frequency $2f$ will be generated in the medium present at the ends of the rod.

As the rod vibrates longitudinally, the following relation governs the frequency of oscillations

$$
f = \frac{m}{2L}\sqrt{\frac{Y}{\rho}}
$$

If it is desired that the frequency of the vibration be same as that of the AC current, a steady ***polarizing magnetic field*** must be applied to the bar.

> A polarizing magnetic field can be produced by passing dc current through a second coil

If the magnitude of the polarizing magnetic field is **greater** than that of the AC field,
frequency of vibration of the bat will be equal to that of the AC magnetic field.

#### Advantages

- Magnetostrictive materials are inexpensive
- Large output power can be produced

#### Disadvantages

- Frequencies higher that 300 kHz cannot be produced
- Single frequency oscillations cannot be generated

### Piezoelectric generator

> **Piezoelectric Effect:**
> When one pair of opposite opposite faces of certain asymmetric crystals such as quartz is compressed,
> opposite electric charges appear on the other pair of opposite faces of the crystals.
> If the crystals are subject to tension (elongation),
> the polarities of the charges are reversed.
> This development of charges as a result of mechanical deformation is known as **direct piezoelectric effect**.
>
> Crystals that exhibit piezoelectric effect are called piezoelectric crystals.
> Examples: Ammonium Phosphate, quartz, PZT (Lead Zirconate Titanate)

> **Inverse Piezoelectric Effect:**
> If an electric field is applied across one pair of faces of a piezoelectric crystal,
> it gets deformed along the direction of the other opposite pair of faces.
> The mechanical deformation of piezoelectric materials caused by external electric field is called **inverse piezoelectric effect**.

Quartz crystal is the most popular choice in making piezoelectric vibrators (transducers).

The frequency of the length vibration of x-cut crystal is:

$$f = \frac{m}{2l}\sqrt{\frac{Y}{\rho}}$$

#### Advantages

- High frequency waves of frequency up to 500 MHz can be generated
- Single frequency output can be obtained
- A range of frequencies can be covered using different transducers

## Detection

### Piezoelectric Detection

Ultrasonic waves are applied to one pair of faces of a quartz crystal.
As a result, varying electric charges are produced on the other pair of faces of the crystal.
These charges, being small, are amplified and detected.

## Ultrasonic Testing

Ultrasonic testing is widely used non-destructive testing (NDT) method.

### Non-destructive Testing

In NDT, frequencies from 100 kHz to 25 kHz.
The ultrasonic waves are generated with piezoelectric devices.

When bursts of alternating voltage are applied to the transducer, the transducer emits ultrasonic beams.
The ultrasonic beams are then transmitted from the transmitter into the specimen under testing.
If there is even a slight discontinuity in the specimen, the ultrasonic waves are reflected back to the transducer.
The transducer then converts the reflected waves back to electrical signals, which are displayed on a screen (CRT).
The characteristics of the pulses produced by the transducer are used for interpretation of the nature and defect in the specimen.

#### Normal Beam Pulse-Echo Testing

An ultrasonic pulse propagating perpendicular to the surface of the test object is reflected at the boundaries of the object
and at the surfaces of defects.
The reflected pulses are known as echoes.

From the transmitter, the electric pulse is fed to the transducer probe.
The piezoelectric transducer is excited by the electric pulse and vibrates at its resonance frequency.
It produces a short ultrasonic pulse, which is propagated into the test object through the couplant layer.
The electric pulse also triggers the time-base generator,
so the pulse of the ultrasound starts to move through the object at the same time as the luminous spot moves across the screen.
If the ultrasonic pulse encounters a defect, part of the energy reflects back to the transducer,
which vibrates and produces a small voltage pulse, which is shown on the screen.
The ultrasonic energy in the transmitted pulse travels further to the bottom and gets reflected back to the transducer,
which is much smaller than transmitted pulse or the pulse reflected from defect.

As the Y-axis of the screen represents time, one can determine the location of the defect in the object.

$$d = \frac{vt}{2}$$

#### Normal beam pulse through-transmission testing

It is used whenever a defect does not provide the required information due to a non-suitable reflection surface,
or if  the orientation is not favourable for detection.

This method uses tow ultrasonic transducers on each side of the specimen.
An ultrasonic pulse, from the transducer is held at the front surface, propagates perpendicularly to the surface.
The transmitted pulses are detected by the second method held at the opposite end of the specimen.

![Normal beam pulse through-transmission testing diagram](./assets/normal-beam-pulse-through-transmission-testing.png)

The transmitter and receiver probes are coupled to the specimen using couplant oil.
The pulse generator excites the transmitting transducer, and an ultrasonic pulse is propagated across the specimen.
The pulse travels through the specimen to the other side, which is amplified and displayed on an oscilloscope.
If the ultrasonic pulse travels without encountering any defect, the signal received will be relatively large.
If there is a defect, some energy is reflected and the signal received on the other end will be reduced.

![Normal beam pulse through-transmission scan representation](./assets/normal-beam-pulse-through-transmission-scan-representation.png)
