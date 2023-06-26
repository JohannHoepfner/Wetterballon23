using System.IO.Ports;
using System.Net;
using System.Text;

namespace RPI;

internal class Program
{
    private const string PortName = "COM7"; // Replace with the correct port name
    private const int BaudRate = 9600; // Replace with the correct baud rate
    private const string FilePath = "c:/tmp/output.txt"; // Path to the output file
    private const string IpAddress = "localhost"; // Replace with the desired IP address
    private const int Port = 8080; // Port for the web server

    private static void Main(string[] args)
    {
        // Create a new SerialPort object
        var serialPort = new SerialPort(PortName, BaudRate);

        // Subscribe to the DataReceived event
        serialPort.DataReceived += SerialPort_DataReceived;

        try
        {
            serialPort.Open();
            Task.Run(StartWebServer);
            Console.WriteLine($"Listening for data on {PortName}. Press any key to exit.");
            Console.ReadKey();
            serialPort.Close();
        }
        catch (Exception ex)
        {
            Console.WriteLine($"An error occurred: {ex.Message}");
        }
    }

    private static void SerialPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
    {
        // Read the incoming data from the serial port
        var serialPort = (SerialPort)sender;
        var data = serialPort.ReadExisting();

        // Output the data to the standard output
        Console.Write(data);

        // Append the data to the file
        File.AppendAllText(FilePath, data);
    }

    private static void StartWebServer()
    {
        using (var listener = new HttpListener())
        {
            // Add the prefixes for the listener
            listener.Prefixes.Add($"http://{IpAddress}:{Port}/");

            try
            {
                // Start listening for incoming requests
                listener.Start();

                Console.WriteLine($"Web server started. Listening on http://{IpAddress}:{Port}/");

                while (true)
                {
                    // Wait for an incoming request
                    var context = listener.GetContext();

                    // Serve the file to the client
                    context.Response.ContentType = "text/plain";
                    context.Response.AddHeader("Cache-Control", "no-cache, no-store, must-revalidate");
                    context.Response.AddHeader("Pragma", "no-cache");
                    context.Response.AddHeader("Expires", "0");
                    var fileContent = File.ReadAllText(FilePath);
                    var buffer = System.Text.Encoding.UTF8.GetBytes(fileContent);
                    context.Response.ContentLength64 = buffer.Length;
                    context.Response.OutputStream.Write(buffer, 0, buffer.Length);
                    context.Response.OutputStream.Close();
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"An error occurred: {ex.Message}");
            }
        }
    }
}
