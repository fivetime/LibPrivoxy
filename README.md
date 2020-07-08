Privoxy is a non-caching web proxy with advanced filtering capabilities for enhancing privacy, modifying web page data and HTTP headers, controlling access, and removing ads and other obnoxious Internet junk. Privoxy has a flexible configuration and can be customized to suit individual needs and tastes. It has application for both stand-alone systems and multi-user networks.<br/>
<br/>
Many people want to integrate Privoxy into their own projects, I made some changes to the Privoxy codes to compiled into a DLL or static library, so that you can better integrate it into their own projects.<br/>
<br/>
Base on work from:
<br/>
Privoxy: https://www.privoxy.org/ (based on its latest version 3.0.28)
<br/>
LibPrivoxy: https://github.com/tarolabs/LibPrivoxy
<br/>
DNS query: https://www.binarytides.com/dns-query-code-in-c-with-winsock/
<br/>
<br/>
Develop environment: Visual Studio 2017<br/>
<br/>
License: GNU GENERAL PUBLIC LICENSE Version 2
<br/>
<br/>
Author: Shiyu Tang <shiyutang#gmail.com>
<br/>
<br/>
Notice: Important changes to original Privoxy:  
  
## Use custom DNS servers
<br />
You can set DNS servers in config file to use specified DNS servers (of example, 8.8.8.8 and/or 208.67.222.222) instead of system-wide DNS settings. You can add no more than 6 DNS servers. Like:  
  
```
dns-servers 8.8.8.8;208.67.222.222
```
### Sample code (C#) of using the dll:
```
public class PrivoxyWrapper
{

    [DllImport(@"LibPrivoxy.dll")]
    public static extern int StartPrivoxy([MarshalAs(UnmanagedType.LPStr)] string configFileFullPath);

    [DllImport(@"LibPrivoxy.dll")]
    public static extern void StopPrivoxy();

	[DllImport(@"LibPrivoxy.dll")]
    public static extern int IsRunning();
}
```
### Sample code (Java#) of using the dll:
```
<!-- https://mvnrepository.com/artifact/net.java.dev.jna/jna -->
<dependency>
    <groupId>net.java.dev.jna</groupId>
    <artifactId>jna</artifactId>
    <version>5.5.0</version>
</dependency>
	
import com.sun.jna.Library;
import com.sun.jna.Native;

public interface LibPrivoxy extends Library {
    LibPrivoxy INSTANCE = Native.load("LibPrivoxy", LibPrivoxy.class);

    int StartPrivoxy(String configFileFullPath);
    void StopPrivoxy();
    int IsRunning();
}
```
