using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Train
{
    struct cmdOption
    {
        bool grep;
    }

    class Cmd
    {
        public Cmd()
        {
        }

        public Cmd(Command _command)
        {
            command = _command;
        }
        
        public Command command;


        public void executeCommand(Command command)
        {
            switch (command.commandArray[0])
            {
                case "grep":
                case "Grep":
                    Console.WriteLine("grep command");
                    Grep grep = new Grep();
                    result = grep.execute(command);
                    break;
            }

            return result;
        }


        void parseCommand(string command)
        {
            


        }

        string[] getCommandWord(string cmd)
        {
            char[] delimiters = new char[] { ' ', '\r', '\n' };
            string[] words = cmd.Split(delimiters, StringSplitOptions.RemoveEmptyEntries);

            return words;
        }
    }
}
