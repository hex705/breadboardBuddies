# A Buddies Buddie

## What is this ? 
To help identify you during your volunteer sessions, we are working (collectively) on creating a buddies, buddie.  The buddie is a circuit that you will place near yourself while in the makerspace and 'on duty' (a problematic and authoritarian term) -- the circuit will tell others that you can be aproached for support.

## Experience
Eventually we need one project file that allows the user to set the 5 dip switches, press enter and have their name displayed, with LCD back ground color and pixel ring color all matching. 

The idea is that a buddie will come in -- power up (oh! Maybe we could set dip switch and just hit reset?  That saves a circuit).  Set your ID on the dip switch and your buddies-buddie is customized. No need to code -- just give it power.

## What Can I do?
We are sort of developing this ad-hoc.  It will have an LCD panel, (which will display your name, and have a background color to match your spreadsheet color) and an LED ring (more of that spreadsheet color), it will have a 5-position dip (dual in-line package) switch for selecting which buddie is using it (think speed dial on a phone from the 80's -- ask your older relatives), it will also need an 'enter' button si it knows you have entered your code on the dip switch ....

Eventually, it needs a body ... so if people want to pitch design ideas back to the discord, you are encouraged to do so -- sketches before you make please -- so we can discuss ideas.

I am trying to sort a solution to managing and developing this -- Steve can lend some time to it on tuesday evenings and at hackNights -- would love to get it done by end of reading week. 

We probalby should learn about pushing and pulling code with github??

## I want to work on it ...  where are the parts?
Check discord for the super secret hiding location ... (lol).


### Circuits:

First we need a working prototype of the 4 circuits (this list needs links):
  
- the ring (***uses neopixel lib*** from adafruit) -- see colorpick file for pixels
- rgb LCD panel -- uses I2C serail comunication-- ***needs lib*** - see colorpick file for LCDs
- dip switch just really compact buttons -- need 5 of them - connected to 5 pins (maybe that should be have been a 6 position switch ??)
- enter button - this can be simple button like those used in tangible (reset?)

Once we have it working ... we will make 4 more so that we have 5 copies.


## Code

Think functions.

Two files for color picking have been developed. They have the basics of making connections to LCD and pixel ring.  See folder --  **buddies-buddie-code**.

We need to develop some code that reads the 5 dips switches once the enter button is pressed -- timers people timers.  OR -- we could just have the switches read once on start up .... (where does that go?) ... 

We need to create some arrays that hold the RGB values for the LCD and the Ring colors as well as the names of each buddie. Positon in array could match buddie index ... there will be lots of blanks -- but that is ok for now.  We can clean this up once it works.

## How do I start?

###Circuits 
-- stuff is in the makerspace, prototype away.

### Code
Quick start -- download this repo and start hacking.

Better way - clone this repo onto your computer via github .. and then push updates back (I know that may make no sense). 




