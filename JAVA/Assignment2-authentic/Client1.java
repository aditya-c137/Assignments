import java.io.*;
import java.net.*;

class Client1{
    public static void main(String[] args){
        try{
            Socket ss=new Socket("192.168.56.1",6080);
            DataOutputStream dout= new DataOutputStream(ss.getOutputStream());
            dout.writeUTF("Sup?");
            dout.flush();
            dout.close();
            ss.close();
        }
        catch(Exception e){}
    }
}