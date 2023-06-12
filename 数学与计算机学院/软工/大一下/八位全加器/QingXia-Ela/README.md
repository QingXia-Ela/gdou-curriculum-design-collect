# 八位加法器

软件：Quartus II

听说还有个四位加法器，不同届应该不一样吧，反正这个八位也是两块四位的拼在一起，凑合着写吧

还得是 zj，大家数电都学的非常好😤

ignore 文件来源：https://gist.github.com/nhasbun/71918796044b7ba89d6662133495f754


以下是原Readme文件
--- 

Altera Complete Design Suite Release 9.1 README.TXT
=================================================================

This readme.txt file accompanies the Quartus II software version 9.1. 



Although we have made every effort to ensure that this version
of the Altera(R) software functions correctly, there may be
problems that we haven't encountered. If you have a question or
problem that is not answered by the information provided in
this readme.txt file, please contact Altera support at 
1-800-800-EPLD or submit a Service Request at mysupport.altera.com.

This readme.txt file contains the following information:
*  Location of Additional Information -- tells you where to find
   additional information about the Altera Complete Design Suite
*  Package Contents -- describes the contents of the Altera Complete
   Design Suite
*  System Requirements -- describes the system requirements for the
   components of the Altera Complete Design Suite

Location of Additional Information
==================================
You can find additional information about the Altera Complete
Design Suite at the following locations:  

Release Notes -- for information about new features, known issues 
and workarounds, timing model status, device support status, 
revision history, and supported versions of other EDA tools, please 
refer to the Quartus II Software Release Notes, the Nios II EDS 
Release Notes, and the MegaCore IP Release Notes, available from the 
Literature page of the Altera website. 

Errata sheets that describe known issues with Altera MegaCore 
functions and Nios II EDS are available from the Literature page 
of the Altera website.

Installation & Licensing -- for information about installing and 
licensing your Altera design software, please refer to the 
Altera Software Installation and Licensing manual, available from 
the Literature page of the Altera website.
        
Package contents
================ 
The Altera Complete Design Suite contains the following tools:

*  Quartus II Design Software including SOPC Builder and MegaCore IP Library
*  ModelSim-Altera Starter Edition VHDL and Verilog HDL Simulation Tool
*  Nios II Embedded Design Suite
*  DSP Builder
                          
                 
You can download software tools and documentation
from the Altera Download Center at the following URL: 
www.altera.com/download
        
The Altera Complete Design Suite also contains the following
technical documentation:
   Introduction to Quartus II manual
   Altera Software Installation and Licensing manual 
   Quartus II Handbook
   Mentor Graphics ModelSim Support chapter
   AN 320: OpenCore Plus Evaluation of Megafunctions
   AN 343: OpenCore Evaluation of AMPP Megafunctions
   Nios II Processor Reference Handbook
   Nios II Software Developer's Handbook

   You can download the most current versions of these
   documents from the Literature pages of the Altera website
   at www.altera.com.    

System Requirements
===================
Software requirements
---------------------
The Quartus II Design Software is supported on the 
following operating systems and versions:
   Windows XP SP2 32-bit 
   Windows XP SP2 64-bit
   Windows XP Pro X64 Edition
   Windows Vista 64-bit
   Windows Vista 32-bit 
   Red Hat Enterprise Linux 4.0 for 32-bit and for AMD64 
     or Intel EMT64 64-bit CPUs
   Red Hat Enterprise Linux 5.0 for 32-bit and for AMD64 
     or Intel EMT64 64-bit CPUs
   SUSE Enterprise Linux 9/10 for 32-bit and for AMD64
     or Intel EMT64 64-bit CPUs
   SUSE Desktop Linux 9/10 for 32-bit and for AMD64
     or Intel EMT64 64-bit CPUs     
   CentOS 4/5 for 32-bit and for AMD64 
     or Intel EMT64 64-bit CPUs
   
The ModelSim-Altera VHDL and Verilog HDL Simulation Tool is supported
on the following operating systems and versions:
   Windows XP SP2 32-bit
   Windows Vista 32-bit 
   Red Hat Enterprise Linux 4.0 for 32-bit 
   Red Hat Enterprise Linux 5.0 for 32-bit 
   SUSE 9 Enterprise Linux 32-bit
   SUSE 10 Enterprise Linux 32-bit
    
The Nios II Embedded Design Suite is supported on the following 
operating systems and versions:
   Windows XP SP2 
   Windows XP Pro X64 Edition
   Windows Vista 32-bit 
   Windows Vista 64-bit 
   Red Hat Linux Enterprise 4.0 for 32-bit and for AMD64 
     or Intel EMT64 64-bit CPUs
   Red Hat Enterprise Linux 5.0 for 32-bit and for AMD64 
     or Intel EMT64 64-bit CPUs  
   SUSE 9 Enterprise Linux
   SUSE 10 Enterprise Linux
   
The Altera MegaCore IP Library is supported on the following 
operating systems and versions:
   Windows XP SP2 32-bit 
   Windows XP SP2 64-bit
   Windows XP Pro X64 Edition
   Windows Vista 64-bit
   Windows Vista 32-bit 
   Red Hat Linux 4.0 for 32-bit and for AMD64 
     or Intel EMT64 64-bit CPUs
   Red Hat Linux 5.0 for 32-bit and for AMD64 
     or Intel EMT64 64-bit CPUs
   SUSE 9 Enterprise Linux
   SUSE 10 Enterprise Linux
   CentOS 4/5 for 32-bit and for AMD64 
     or Intel EMT64 64-bit CPUs
                        
   Some MegaCore functions do not support all the listed operating 
   systems. Refer to the user guide for the individual MegaCore
   function. Additional software, such as MATLAB, is required for 
   some MegaCore functions. Refer to the User Guide for the 
   individual MegaCore function.

DSP Builder is supported on the following operating systems and versions:
   All operating systems supported by the Quartus II software.
   The following additional software is required to run DSP Builder:
      The MathWorks releases R2007b, R2008a, R2008b, or R2009a 
      (only the 32-bit versions are supported)
   The DSP Builder Advanced blockset uses Simulink fixed-point 
      types for all operations and requires licensed versions of the 
      Simulink Fixed-Point Blockset and Fixed-Point Toolbox. 
      The Signal Processing Blockset and Communications Blockset are also
      recommended and are used in many of the demonstration designs.
   The Quartus II software version 9.1.
   
Browser
   The Quartus II software uses a web browser to display the 
   interactive tutorial and certain other features. If your 
   operating system does not provide a default browser, you must 
   configure a web browser in the Internet Connectivity page of 
   the Options dialog box. 
   
FLEXlm
   The Altera Complete Design Suite uses the FLEXlm license server 
   software to support network (multiuser) licensing. 
   If it is not installed, the Quartus II installation process 
   installs it automatically. However, if you already have FLEXlm 
   license server software installed for an application other than 
   the Quartus II or MAX+PLUS(R) II software, you should verify 
   that the version is FLEXlm 9.5 or later.
   
Display Manager
   Linux
      KDE version included in Red Hat distribution
      Gnome version included in Red Hat distribution
                        
Hardware requirements/recommendations
-------------------------------------
   Pentium III or later for Windows or Linux 
   Color display capable of 1024 X 768 pixel resolution
   DVD drive
   One or more of the following I/O ports:
   -  USB port (if using Windows XP or Windows 2000) for 
      USB-Blaster(TM) or MasterBlaster(TM) 
      communications cables, or APU programming unit
   -  Parallel port for ByteBlasterMV(TM) or 
      ByteBlaster(TM) II download cables

Memory requirements/recommendations
-----------------------------------
Please see the Quartus II Device Support Release Notes for 
information on memory requirements and recommendations.

		  