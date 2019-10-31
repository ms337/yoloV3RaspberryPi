Submission Code in branch Stage3SubmFinal, and also attached.

Following are the steps to setup and build the program:

0. Setup RaspberryPi VM. Ensure you have make and cmake installed. You can do so by running 'cmake' and 'make' respectively.  

1. Installing OpenCV
    The steps are based on the the tutorial linked at:
    https://docs.opencv.org/4.1.1/d7/d9f/tutorial_linux_install.html

    1. Run 'sudo apt-get install build-essential' from Terminal. 
    2. Run 'sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev'
    3. Download the Source archive from https://github.com/opencv/opencv/archive/4.1.1.zip
    4. Extract the archive and put the extracted folder into your ~ folder. So the path of the extracted folder should now be '/home/pi/opencv-4.1.1'
    5. cd ~/opencv
    6. mkdir build
    7. cd build
    8. Now run 'cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local ..' while you are in the build folder after 5.
    9. Once finished, still in the build directory run 'make -j7 # runs 7 jobs in parallel'
        This step is going to take ~20 mins. The installation may fail and stop in the middle. Just run the command again and it will resume. 
    10. Once above step is finished, while still in the make directory, run 'sudo make install'


2. Installing Qt

    The steps to install Qt are default using the Qt Online Installer which can be downloaded from www.qt.into

    1. Go to qt.io/download
    2. Scroll down to 'Downloads for open source users', click on the green open source button. 
    3. Scroll down all the way and click on the 'Download Qt Online Installer' button. 
    4. Ensure the version being downloaded is for 32 bit linux. You can select this using 'View other options' link. 
    5. The download should start. Once complete, cd into ~/Downloads from your terminal.
    6. Run 'chmod a+x {the downloaded file}'
    7. Run './{the downloaded file}'
    8. Follow the installation steps. You will need a Qt account so create one if needed. 
    9. Leave the Installation Folder path as it is. It should be '/home/pi/Qt'.
    10. In the Select Components stage, leave the options and checkboxes as they are. 
    11. Agree to the terms and conditions.
    12. Installation will run. 




3. Git clone the project repository.
    1. cd into the repository.
    1.1 'git checkout Stage3SubmFinal'
    2. Run cmake . In all probability this will give your errors. Essentially these are errors about linking the library files.
        If you have no errors, skip ahead. 

    3. So first we will have to specify the path to OpenCV for cmake. This will be done by running the following command: 
        'cmake -DOpenCV_DIR=/home/pi/opencv-4.1.1/build .'
        This is essentially letting cmake know where the opencv library files are. 
        But this will now still show an error for Qt. It will say somthing like "FindQt5.cmake" not provided.

    4. Now we specify path for our Qt libraries:
       RUN 'cmake -DCMAKE_PREFIX_PATH=/home/pi/Qt/5.5/gcc/lib/cmake/Qt5 .'

    5. [May Happen] You may get and error saying "Failed to find "GL/gl.h" in "/usr/include/libdrm".
        To solve this run 'sudo apt-get install mesa-common-dev'
    
    6. Now run 'cmake -DCMAKE_PREFIX_PATH=/home/pi/Qt/5.5/gcc/lib/cmake/Qt5 .'
        Even just 'cmake .' should suffice.
        CMake should build everything now. 

    7. Run 'make'. This will generate Main.out

    8. Run './Main.out' to run the program.

    9. You will get an eror regarding no camera found at index 0. 

    10. So you will have to setup the camera on your RaspberryPi. 
        Follow this tutorial here: https://scribles.net/using-webcam-in-virtualbox-guest-os-on-windows-host/?fbclid=IwAR3FZtVm3PcogQfRSKEOmzG1aabjW2qFNqeGedRLiFEDpYAwQMOQJpCrBxA
        Skip the verification step with cheese because that is not compatible with the OS. 
        You can follow other tutorials too but essentially we need RaspberryPi to have access to camera, and by default the first camera will be at index 0 which is what the program will use. 
        
        You might need to start the VM through the terminal using 'vboxmanage startvm {vmname}' if the camera is not found. 

    





