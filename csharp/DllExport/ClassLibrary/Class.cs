using RGiesecke.DllExport;
using System;

namespace ClassLibrary
{
    public class Class
    {
        [DllExport]
        public static void Print()
        {
            Console.WriteLine("Hi from C# - DllExport");
        }
    }
}