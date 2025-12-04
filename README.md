[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=21698586)
# ELEC2645 Unit 2 Enginnering calculator project

1. overview:
    This project is aim to creat a multifunctional engineering tool:
    
    Scientific & Mathematics Tools: 

        Unit conversion 

        basic statistics 

    Electronic & Electrical Engineering (EEE) Tools:

        RC filter calculator
        
        Resistor network calculator

    The program allows users to perform unit conversions, basic statistical analysis, RC filter calculations, and resistor network calculations.

2. Details: 

    Unit Conversion

        Hz <-> rad/s

        dBm <-> mW

    Basic Statistics

        Minimum

        Maximum

        Mean 

    RC Filter Calculator

    Computes the cutoff frequency.

    Resistor Network Calculator

        Series resistance

        Parallel resistance

3. Running:
    
    build with the code:
    
        make

    run:

        ./main.out

    rebuild:

        make -b

4. Files:
    
    main.c:
    	
    Handles main menu, program flow.
    
    funcs.c:
    
    submenu logic.
    
    funcs.h:
    
    Header file.
    
    Makefile:
    
    Build script for compiling the project.
    
    README.md:
    
    Project documentation.

5. Future improvements:

    Additional filter calculators, such as high-pass and band-pass.
    
    Adding an AI assistant to facilitate communication with customers.