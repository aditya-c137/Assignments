import java.io.*;
import java.net.*;

class Server1{
    public static void main(String[] args){
        try{
            ServerSocket ss=new ServerSocket(6080);
            System.out.println("where u at...?");
            Socket s = ss.accept();
            DataInputStream din= new DataInputStream(s.getInputStream());
            String st = (String)din.readUTF();
            System.out.println("Client says: "+st);
        }
        catch(Exception e){}
    }
}