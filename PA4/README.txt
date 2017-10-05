ASSIGNMENT 4: Event Driven Simulation
AUTHORS: Clayton Dembski & Floris van Rossum
USERNAMES: cjdembski & fjvanrossum
LAST UPDATED: October 5th 2017, 1:33 PM

FILES INCLUDED:
qSim.cpp
CustEvent.cpp
CustEvent.h
Event.cpp
Event.h
EventQueue.cpp
EventQueue.h
TellerEvent.cpp
TellerEvent.h
TellerList.cpp
TellerList.h
TypesOfAction.h
makefile
README.txt

HOW TO USE:
Running make all will compile the code without warnings and generate a executable
called qSim. Running qSim with compatible arguments will run the program. 
	
	./qSim #customers #tellers simulationTime averageServiceTime <seed>
	
This line will run the program. customers, tellers, simulationTime averageServiceTime
must be entered to run the program. The seed variable is optional. customers,
tellers and simulationTime should be a whole integer value while averageServiceTime
can be a value with decimals.

Running the program with the correct arguments will execute the program as defined 
by assignment 4. Improperly entering the command line arguments as specified above 
will print an error and exit the program. Assuming the program runs correctly the
program will run two simulations and print out the statistics of both simulations 
once the program is complete. When the program is complete all nodes and objects used
during runtime are properly freed and deleted. More information about how the program
runs can be found later on in the README file under PURPOSE and PROGRAM STRUCTURE &
ORGANIZATION.

DOXYGEN:


PURPOSE:


PROGRAM STRUCTURE & ORGANIZATION:

Explain how you represented tellers events and customers:

Algorithm explanation:

DISCUSSION:
Common queuing vs. per-teller queuing:


PROGRAM FLOW:


LOOP INVARIANTS:

PROBLEMS:

TEST CASES:

SOURCES:
1. http://en.cppreference.com/w/cpp/language/abstract_class
2. https://www.git-tower.com/learn/git/faq/change-author-name-email
3. http://www.cplusplus.com/doc/tutorial/typecasting/
4. http://www.cplusplus.com/reference/cstdlib/rand/
5. https://stackoverflow.com/questions/3001336/c-delete-a-struct
6. https://www.tutorialspoint.com/c_standard_library/c_function_strtol.htm
7. https://stackoverflow.com/questions/120876/what-are-the-rules-for-calling-the-superclass-constructor
8. https://en.wikipedia.org/wiki/Circular_dependency#Example_of_circular_dependencies_in_C.2B.2B
9. https://stackoverflow.com/questions/71959/one-file-doesnt-recognize-other-files-class-in-c
10. https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.cbclx01/overload_member_fn_base_derived.htm
11. https://stackoverflow.com/questions/2574276/java-how-can-a-constructor-return-a-value
12. https://canvas.wpi.edu/courses/4966/files/folder/Class%20Slides?preview=740902
13. https://canvas.wpi.edu/courses/4966/files/folder/Class%20Slides?preview=725194

















