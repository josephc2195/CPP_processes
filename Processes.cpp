#ifndef Processes_cpp
#define Processes_cpp

#include "Processes.h"

using namespace std;


// Part 1: Working With Process IDs
pid_t getProcessID(void)
{
  //created new pid object
   pid_t id = getpid();
   return id;
}


string createNewProcess(void)
{
   pid_t id = fork();
   process_id = id;

   //if a child process could not be created
   if(id == -1)
   {
      return "Error creating process";
   }

   //currently on the child process
   else if (id == 0)
   {
      cout << "I am a child process!" << endl;
      return "I am bored of my parent, switching programs now";
   }

   //once its back to the parent process
   else
   {
      cout << "I just became a parent!" << endl;
      int status = 0;
      wait(&status);

      return "My child process just terminated!";
   }
}


// Part 3: Working With External Commands"
void replaceProcess(char * args[])
{
   // Spawn a process to execute the user's command.
   pid_t id = fork();


   // TODO: Add your code here
   execvp(args[0], args);
}

#endif /* TestProg_cpp */
