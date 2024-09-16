# Acoustics

<!--toc:start-->
- [Acoustics](#acoustics)
  - [Syllabus](#syllabus)
  - [Introduction](#introduction)
    - [Properties of Sound Waves](#properties-of-sound-waves)
    - [Classification of Sound](#classification-of-sound)
  - [Characteristics of Sound](#characteristics-of-sound)
    - [Pitch or Frequency](#pitch-or-frequency)
    - [Timbre or Quality](#timbre-or-quality)
    - [Loudness or Intensity](#loudness-or-intensity)
    - [Weber-Fechner Law](#weber-fechner-law)
  - [Decibel Scale](#decibel-scale)
<!--toc:end-->

---

title: Ultrasonics Notes - Engineering Physics Semester 1

author: Pranaov S

lecturer: Dr. Sudipta Som

code: PH1001T

---

## Syllabus

Classification - Music and Noise

Characteristics of Sound: Pitch/Frequency, Loudness/Intensity

Decibel Scale

Weber-Fechner Law

Loudness Curves

Quality/Timbre

## Introduction

A vibrating body excites mechanical waves in the surrounding medium.
These mechanical waves travel as a series of compressions and rarefactions of air molecules.
On reaching the ear, they cause the eardrum to vibrate, leading to the sensation of hearing.

### Properties of Sound Waves

- Requires an elastic medium for propagation.
- Longitudinal waves

The compressions and rarefactions modulate the normal atmospheric pressure with small pressure changes above and below it.
Hence, a sound wave is one complete variation of pressure variation.

The average maximum distance from a particle to its mean position is called __amplitude__.

The velocity of sound in a gaseous medium is $v = \sqrt{\frac{B}{\rho}}$, where $B$ is bulk modulus and $\rho$ is density.
Speed of sound is taken as 344 m/s in normal conditions.

### Classification of Sound

1. Audible waves: 16 (20) Hz to 20 kHz
    1. Musical sound: Produce a pleasing sensation in the ear
        - Line spectrum containing multiple frequencies
        - Periodic vibrations
        - Sudden changes in amplitude does not occur.
    2. Noise: Causes irritation and strain to ears
        - If it is very loud, noise may cause temporary or permanent deafness.
        - Irregularly timed, non-periodic vibration
        - Complex spectrum of frequencies
        - Erratic changes in amplitude and frequencies
2. Infrasonic waves: < 16 Hz
3. Ultrasonic waves: > 20 kHz
4. Hypersonic waves: > $10^{10}$ Hz and correspond to thermal waves in liquids or solids.

## Characteristics of Sound

A musical note consists of several tones of different frequencies of varying intensities.
The _pitch_ of the note corresponds to the lowest note it contains.

> __Tone:__ A tone is a sound wave, which has a single well defined frequency

The lowest pitch tone of a frequency $f$ is the loudest and is called __fundamental tone__.
The frequency is dominant and defines pitch of the note.
Additional frequencies like $2f, 3f, 4f, \dots, nf$ are called __overtones__ or __harmonics__.

$\textrm{Intensities of overtone } \propto \frac{1}{\textrm{frequency}}$

### Pitch or Frequency

It enables us to classify a musical note as high or low/shrill or flat from a sound of same intensity from the same musical instrument.
Highness or lowness of a sound is characterized by the frequency producing it.

__Definition:__
Pitch is a _subjective_ sensation perceived when a tone of given frequency is sounded.
The pitch of the note depends on the frequency of the source of the sound.
$$\textrm{Frequency} \propto \textrm{Pitch}$$

Frequency is a _physical_ quantity that can be be measured accurately.
Pitch is a _psychological_ quantity which is merely a sensation experienced by the listener.

The change in pitch with loudness is most pronounced at a frequencies of about 100 Hz.
In 100 Hz range, pitch $\propto$ loudness.
For frequencies between 1 kHz and 5 kHz (most sensitive), pitch is relatively independent of its loudness.
Generally, pitch varies in a parabolic manner with frequency in in range 20 Hz to 10 kHz.

### Timbre or Quality

Timbre is the name given to subjective sensation,
which enables us to differentiate the same note played on different instruments of same amplitude and frequency.

__Definition:__
Timbre gives distinguishes nature of a tone.
The difference between the notes of the same pitch of two different musical instruments defines the quality of note produced by an instrument.
Quality distinguishes  the note produced from one instrument from that of another.

If two musical notes have the same fundamental frequency (pitch) but differ in overtones, they are said to differ in quality.

### Loudness or Intensity

Loudness signifies how far, and to what extent, sound is audible. Loudness of sound is objective.
An objective measurement of loudness is sound _intensity_. Intensity is a physical quantity and does not depend on listener.

__Definition:__
The intensity of the sound wave is the rate of flow of sound energy through a unit area normal to the direction of propagation.
Since rate of flow of energy is power, the intensity of sound wave is measured in units of power per unit area $\frac{W}{m^{2}}$.

$$I \propto P^{2}$$

Where $P$ is pressure amplitude.

Intensity of faintest sound wave that can be heard is about $10^{-12} W/m^{2}$.
The range of intensities that can be heard is from $10^{-12} W/m^{2}$ to about $1 W/m^{2}$.

### Weber-Fechner Law

__Definition:__
Weber-Fechner law states that the degree of sensation of sound is proportional to the logarithm of the stimulus producing the sound.

$$L = k \log I$$

Where $k$ is proportionality constant and depends on sensitivity of ear, quality of sound, etc.

If intensity is doubled:

$$L_{2} - L_{1} = k \log 2$$

Loudness increases by the same level whenever intensity is doubled.

## Decibel Scale

The loudness of sound judged by the ear is proportional to logarithm of intensity.

Lowest intensity of sound at 1 kHz to which the human ear can respond is $I_{0} = 10^{-12} W/m^{2}$.
This is known as __Threshold of Hearing__, and is chosen as _zero_ or _standard_ intensity.
Intensity of sound is measured with reference to that frequency.

__Definition:__
The ratio of intensity of sound wave to the threshold intensity of hearing is defined as _intensity level_.

$$L = \log \frac{I}{I_{0}}\textrm{bels}$$

L is called intensity level and is expressed in bels.

$$1 \textrm{ decibel} = \frac{1}{10}\textrm{ bel}$$

$$L = 10 \log \frac{I}{I_{0}}dB$$

- 0 dB represents __threshold of audibility__
- A change in intensity by 26% increases the intensity level by 1 dB.
- The loudest sound that can be heard without pain is about 120 dB.
This is known as __threshold of feeling__ or __pain threshold__.
