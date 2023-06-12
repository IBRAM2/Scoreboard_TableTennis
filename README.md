# Tennis Scoreboard

## Simulation
The software used to perform the circuit simulations is proteus, this software its not free, so I provide a "student" version below.

Download Link: [Proteus Student Version](https://drive.google.com/drive/folders/1Nruetk5m6KCmWx57GLWE98xntiZ9FSeq?usp=drive_link)

### Installation Instructions

You need Windows OS to install proteus
1. Install the .exe, the default ***installation_path*** is: 
    > C:\Program Files (x86)\Labcenter Electronics\Proteus 8 Professional

2. On ***installation_path***/DATA/LIBRARY paste the contents of **"librerias-arduino"**

3. (Optional) On ***installation_path*** remplace Translations directory with the content of **"Paquete de idiomas"**.

### Run Simulation
1. Open **Arduino IDE**, go to File, preferences, and select verbose on compilation.

2. Compile the program, Towards the end of the terminal output, you will be able to see the path where the program was compiled
    > C:\\Users\\name\\AppData\\Local\\Temp\\arduino-sketch-38788937E004AF96E05C05CDE8CDFB3A\Scoreboard.ino.elf
    >
    Copy the path from the terminal or locate the indicated path, remember that the separators are \ and remove the " at the beginning and end.

3. Open the simulation, and double click on arduino nano, paste the path of the file .elf or .hex on **Program File:**

4. Run the simulatior by clicking on the play symbol in the bottom left corner.

*Note: Due to Arduino compiling the program into temporary files, it's possible that program execution may modify the path. However, this usually doesn't happen within the same session unless you restart the computer.*