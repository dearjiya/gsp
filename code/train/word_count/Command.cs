using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Train
{
    enum CommandType
    {
        None = 0,
        grep = 1,
    }
    class Command
    {
        public CommandType commandType = CommandType.None;
        public string[] commandArray;

        public Command(string str)
        {
            setCommand(str);
        }

        void setCommand(string str)
        {
            char[] delimiters = new char[] { ' ', '\r', '\n' };
            commandArray = str.Split(delimiters, StringSplitOptions.RemoveEmptyEntries);
            commandType = (CommandType)Enum.Parse(typeof(CommandType), commandArray[0].ToString());
        }
    }

    public static class ExtensionMethods
    {
        public static T ToEnum<T>(this string value)
        {
            if (!System.Enum.IsDefined(typeof(T), value))
                return default(T);

            return (T)System.Enum.Parse(typeof(T), value, true);
        }
    }
}
