using System.IO.Ports;

namespace RPI;

internal class Program
{
    private const int BaudRate = 9600; // Replace with the correct baud rate
    private const string FilePath = "c:/tmp/output.txt"; // Path to the output file

    private static void Main(string[] args)
    {
	    var portNames = SerialPort.GetPortNames();
        foreach (var portName in portNames)
        {
            Console.WriteLine("Serial Port: " + portName);
        }
        var USBserialPorts = portNames.Select(x => new SerialPort(x,BaudRate)).ToList();

        foreach (var sPort in USBserialPorts)
        {
            sPort.DataReceived += SerialPort_DataReceived;
        }
       
        foreach (var sPort in USBserialPorts)
        {
            sPort.Open();
        }
        
        Console.WriteLine("Listening for serial data...");
        
        
        while (true)
        {
            foreach (var sPort in USBserialPorts.Where(sPort => !sPort.IsOpen))
            {
                sPort.Open();
            }
            Thread.Sleep(1000);
        }
    }

    private static void SerialPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
    {
        var serialPort = (SerialPort)sender;
        var data = serialPort.ReadLine();
        
        var writeString = $"{serialPort.PortName}: {data}";
        Console.WriteLine(writeString);
        File.AppendAllText(FilePath, writeString+'\n');
    }
}
