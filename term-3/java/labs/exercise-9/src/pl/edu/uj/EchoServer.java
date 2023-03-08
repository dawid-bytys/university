package pl.edu.uj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class EchoServer {
    private static final int PORT = 3000;
    private static final int POOL_SIZE = 10;

    public static void main(String[] args) throws IOException {
        ExecutorService threadPool = Executors.newFixedThreadPool(POOL_SIZE);
        try (ServerSocket serverSocket = new ServerSocket(PORT)) {
            System.out.println("Server started on port " + PORT);

            while (true) {
                Socket socket = serverSocket.accept();
                threadPool.submit(new EchoServerTask(socket));
                System.out.println(socket.getInetAddress().getHostName() + " has connected!");
            }
        }
    }

    private record EchoServerTask(Socket socket) implements Runnable {
        @Override
            public void run() {
                try {
                    PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
                    BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

                    System.out.println("Prime task started for " + socket.getInetAddress().getHostName());

                    int from = Integer.parseInt(in.readLine());
                    int to = Integer.parseInt(in.readLine());

                    StringBuilder primes = new StringBuilder();
                    for (int i = from; i <= to; ++i) {
                        if (isPrime(i)) {
                            primes.append(i).append(" ");
                        }
                    }

                    System.out.println("Prime task finished for " + socket.getInetAddress().getHostName());
                    out.println(primes);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }

            private static boolean isPrime(int number) {
                if (number <= 1) {
                    return false;
                }
                for (int i = 2; i <= Math.sqrt(number); ++i) {
                    if (number % i == 0) {
                        return false;
                    }
                }
                return true;
            }
        }
}
