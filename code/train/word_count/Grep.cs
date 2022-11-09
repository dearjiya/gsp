using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;



namespace Train
{
    struct Options
    {
        public bool i;  // 대소문자 구분안함
        public bool c;  // 매칭되는 행의 수 출력
        public bool h; // 복수 파일에서 검색
    }

    enum Option
    {
        i = 1,
        c = 2,
        h = 3
    }

    /// <summary>
    /// grep [Option] [Pattern] [FileName]
    /// 파일에서 일치하는 행을 찾아 출력한다
    /// </summary>
    class Grep
    {
        string option;
        string pattern;
        string fileName;

        public string execute(string[] words)
        {
            if(words.Length == 4)
            {
                checkOption(words[1]);
                checkPattern(words[2]);
                checkFile(words[3]);
                
            }
            else
            {
                checkFile(words[1]);
                if(words.Length == 3)
                {
                    checkPattern(words[1]);
                    checkFile(words[2]);
                }
            }

        }

        void checkOption(string opt)
        {
            switch(opt)
            {
                case "i":
                    option = "i";
                    break;
                case "c":
                    option = "c";
                    break;
                case "h":
                    option = "h";
                    break;
                default:
                    option = null;
                    break;
            }
        }

        void checkPattern()
    }
}
