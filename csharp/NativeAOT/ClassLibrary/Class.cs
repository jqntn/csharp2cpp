using System.Runtime.InteropServices;

namespace ClassLibrary
{
    public class Class
    {
        [UnmanagedCallersOnly(EntryPoint = "Print")]
        public static void Print()
        {
            Console.WriteLine("Hi from C# - NativeAOT");
        }
    }
}