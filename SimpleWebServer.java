import java.io.*;                                         
import java.net.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;                                       
 
public class SimpleWebServer {                            
 
    /* Run the HTTP server on this TCP port. */           
    private static final int PORT = 8080;     
	
	private static final int downloadsize = 1000;
 
    /* The socket used to process incoming connections
       from web clients */
    private static ServerSocket dServerSocket;     
	
	private String user = "nikki";
	private String pass = "123qwe";

	public boolean checkUser(String authHeader) {
		String encodedUP = authHeader.substring("Basic ".length()).trim();
		byte[] decodedBytes = Base64.getDecoder().decode(encodedUP);
		String decodedString = new String(decodedBytes);
		String userN = decodedString.split(":")[0].trim();
		String passW = decodedString.split(":")[1].trim();

		if(userN.equals(this.user) && passW.equals(this.pass)){
			return true;
		}

		else{
			return false;
		}
	}	

    public SimpleWebServer () throws Exception {          
 	dServerSocket = new ServerSocket (PORT);          
    }                                                     
 
    public void run() throws Exception {                 
	while (true) {                                   
 	    /* wait for a connection from a client */
 	    Socket s = dServerSocket.accept();           
 
 	    /* then process the client's request */
 	    processRequest(s);                           
 	}                                                
    }                                                    
 
    /* Reads the HTTP request from the client, and
       responds with the file the user requested or
       a HTTP error code. */
    public void processRequest(Socket s) throws Exception { 
 	/* used to read data from the client */ 
 	BufferedReader br =                                 
 	    new BufferedReader (
				new InputStreamReader (s.getInputStream())); 
 
 	/* used to write data to the client */
 	OutputStreamWriter osw =                            
 	    new OutputStreamWriter (s.getOutputStream());  
     
 	/* read the HTTP request from the client */
 	String request = br.readLine();                    
 	String command = null;                             
 	String pathname = null;                            
     
 	/* parse the HTTP request */
 	StringTokenizer st = 
	    new StringTokenizer (request, " ");               
 
 	command = st.nextToken();                       
 	pathname = st.nextToken();                      
 
	if (command.equals("GET")) {                    
	    /* if the request is a GET
	       try to respond with the file
	       the user is requesting */
	    serveFile (osw,pathname);        
	    logEntry("logFile.txt", command);           
 	} 
 	else if (command.equals("PUT")) {                    
	    /* if the request is a PUT
	       try to respond with the file
	       the user is requesting */
	    serveFile (osw,pathname);      
	    logEntry("logFile.txt", command);           
 	       
 	}                                                                                   
 	else {                                         
	    /* if the request is a NOT a GET,
	       return an error saying this server
	       does not implement the requested command */
	    osw.write ("HTTP/1.0 501 Not Implemented\n\n");
 	}                                               
 	
 	/* close the connection to the client */
 	osw.close();                                    
    }                                                   
 
    public void serveFile (OutputStreamWriter osw,      
			   String pathname) throws Exception {
 	FileReader fr=null;                                 
 	int c=-1;
	int bytesSent = 0;                                           
 	StringBuffer sb = new StringBuffer();
       
 	/* remove the initial slash at the beginning
 	   of the pathname in the request */
 	if (pathname.charAt(0)=='/')                        
 	    pathname=pathname.substring(1);                 
 	
 	/* if there was no filename specified by the
 	   client, serve the "index.html" file */
 	if (pathname.equals(" "))                            
 	    pathname="";                          
 
 	/* try to open file specified by pathname */
 	try {                                               
 	    fr = new FileReader (pathname);                 
 	    c = fr.read();                                  
 	}                                                   
 	catch (Exception e) {                               
 	    /* if the file is not found,return the
 	       appropriate HTTP response code  */
 	    osw.write ("HTTP/1.0 404 Not Found\n\n");         
 	    return;                                         
 	}                                                   
 
 	/* if the requested file can be successfully opened
 	   and read, then return an OK response code and
 	   send the contents of the file */
 	if(Files.size(Paths.get(pathname)) <= downloadsize){
		osw.write ("HTTP/1.0 200 OK\n\n");                    
		while (c != -1 && bytesSent <= downloadsize) {    
			bytesSent++;   
			sb.append((char)c);                            
			c = fr.read();                                  
		}                                                   
 		osw.write (sb.toString());                                  
    }    
	
	else{
		osw.write("HTTP/1.0 403 Forbidden\n\n");
		logEntry("errorlog.txt", "File too large" + Inet4Address.getLocalHost());
	}
	 }
	
	                          
 
    /* This method is called when the program is run from
       the command line. */

	public void storeFile(BufferedReader br, OutputStreamWriter osw, String pathname) throws Exception{
		FileWriter fw= null;

		try{
			fw = new FileWriter(pathname);
			boolean autherization = false;
			String s = br.readLine();

			while (s != null && s.length() > 0){
				if (s.contains("Basic")){
					autherization = true; 
					
					if(!checkUser(s.substring(s.indexOf("Basic")))){
						osw.write("HTTP/1,0 403 Forbidden \n\n");
						logEntry("errorLogs.txt", "Incorrect Auth");
						osw.close();
						return;
					}
				}

			}

			if(!autherization){
				osw.write("HTTP/1.0 401 Unauthorized \n\n");
			}



			osw.write("HTTP/1.0 201 Created");
			s = br.readLine();

			while (s != null && s.length() > 0){
				fw.append(s);
				s = br.readLine();
			}
			
			fw.close();


		} catch (Exception e){
			osw.write("HTTP/ 1.0 500 Internal Server Error");
		}
	}

	public void logEntry(String filename, String record){
		try{
			FileWriter fw = new FileWriter(filename, true);
			fw.write(getTimeStamp() + " " + record);
			fw.close();
		} catch(IOException e ){
			return;
		}
	}

	public String getTimeStamp() {
		return(new Date()).toString();
	}
    public static void main (String argv[]) throws Exception { 
 
		// /* Create a SimpleWebServer object, and run it */
		SimpleWebServer sws = new SimpleWebServer();           
		sws.run();  
    }                                                          
} 
