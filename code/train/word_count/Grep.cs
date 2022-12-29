using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;



namespace Train
{
    enum GrepOption
    {
        n = 0,   // 옵션이 없는 상태: 기본 grep 기능을 한다
        c = 1,   // 매칭되는 행의 수 출력
        h = 2,    // 폴더에서 검색
        i = 3   // 대소문자 구분안함
    }

    struct OptionSettings
    {

    }

    /// <summary>
    /// grep [Option] [Pattern] [FileName]
    /// 파일에서 일치하는 행을 찾아 출력한다
    /// </summary>
    class Grep
    {
        public Command command;
        public GrepOption option = GrepOption.n;
        public string pattern = "";
        public string filePath = "";

        Dictionary<GrepOption, bool> options = new Dictionary<GrepOption, bool>();

        bool[] settings = new bool[System.Enum.GetValues(typeof(GrepOption)).Length];

        int optionCount = 0;

        public Grep(Command _command)
        {
            command = _command;

            setArgs(command.commandArray.Length);
        }


        public void execute()
        {
            checkOption();
        }

        void setArgs(int len)
        {
            if(len < 2)
            {
                Console.WriteLine("wrong option count");
                // exception 처리
            }

            if(len == 2)
            {
                pattern = command.commandArray[len - 1];
                return;
            }

            // commandtype 부분 빼기
            len--;
            
            optionCount = len - 2;

            for (int i = 0; i < optionCount; i++)
            {
                var index = (int)Enum.Parse(typeof(GrepOption), command.commandArray[i + 1].ToString());
                settings[index] = true;

                //option = (GrepOption)Enum.Parse(typeof(GrepOption), command.commandArray[i + 1].ToString());
                //GrepOption key = (GrepOption)Enum.Parse(typeof(GrepOption), command.commandArray[i + 1].ToString());
                //// options.Add((GrepOption)Enum.Parse(typeof(GrepOption), command.commandArray[i + 1].ToString()));
                //options.Add(key, true);
                //Console.WriteLine("key: "+ key);
                //Console.WriteLine("value: " + options[option]);
            }
            pattern = command.commandArray[len - 1];
            filePath = command.commandArray[len];

        }

        void checkOption()
        {
            Console.WriteLine("execute command: " + command.commandStr);
            switch (optionCount)
            {
                case 0:
                    noneOpt();
                    break;
                case 1:
                    if (settings[(int)GrepOption.c])
                    {
                        matchCountOpt();
                    }

                    if (settings[(int)GrepOption.h])
                    {
                        folderMatch();   
                    }

                    if (settings[(int)GrepOption.i])
                    {
                        ignoreOpt();
                    }
                    break;
                case 2:
                    if (settings[(int)GrepOption.c] && settings[(int)GrepOption.i])
                    {
                        ignoreMatchCount();
                    }
                    if (settings[(int)GrepOption.h] && settings[(int)GrepOption.i])
                    {
                        ignoreFolder();
                    }
                    if (settings[(int)GrepOption.c] && settings[(int)GrepOption.h])
                    {
                        matchCountFolder();
                    }
                    break;

                case 3:
                    ignoreMatchCountFolder();
                    break;
            }
        }


        void noneOpt()
        {
            LineCounter noncounter = new LineCounter();
            List<string> lines = noncounter.getMatchLine(pattern, filePath);
            Console.WriteLine("---Result---");
            foreach (var line in lines)
            {
                Console.WriteLine(line);
            }
            Console.ReadLine();
        }

        //c
        void matchCountOpt()
        {
            LineCounter counter = new LineCounter();
            int res = counter.isMatchCount(pattern, filePath);
            Console.WriteLine("Result: " + res);
            Console.ReadLine();
        }

        // c,h
        void matchCountFolder()
        {

        }

        // i
        void ignoreOpt()
        {

        }

        // i, c
        void ignoreMatchCount()
        {

        }

        // i, h 
        void ignoreFolder()
        {

        }

        // h
        void folderMatch()
        {

        }

        // i, c, h
        void ignoreMatchCountFolder()
        {

        }
    }
}
