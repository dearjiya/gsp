using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Train
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("command >> ");
            string str = Console.ReadLine();
            Command command = new Command(str);
            Cmd cmd = new Cmd(command);
            cmd.executeCommand(command);
            Console.WriteLine("request command: " + command);

            //LineCounter counter = new LineCounter();
            //int res = counter.isMatchCount("hello", "linetest.txt");
            //Console.WriteLine(res);
            //Console.ReadLine();
        }
    }
}
