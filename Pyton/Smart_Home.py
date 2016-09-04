#Created on: 24-Mar-2016
#Author: Roshan Prakash, Project MANAS
#This code cannot be shared, modified, distributed without prior written permission from its authors.

import serial
import MySQLdb
import time
db = MySQLdb.connect("projectmanas.local","manas","fi@manas","MANAS" )
c = db.cursor()
ser = serial.Serial('/dev/ttyACM1',9600,timeout=0)
while 1:
      ser.write('1')
      rfid=ser.readline()
      rfid=rfid.replace('\n','')
      rfid=rfid.replace('\r','')
      date= (time.strftime("%Y-%m-%d"))
      c.execute("SELECT Counter FROM Counter_stamp WHERE Status =667676")#Checking Total counter days
      counter=c.fetchone()[0]
      c.execute("SELECT Date_stamp FROM Counter_stamp WHERE Status = 667676")#checking date of Counter_stamp table
      counter_date=c.fetchone()[0]
      if date != counter_date:
         counter= counter +1
         c.execute("UPDATE Counter_stamp SET Date_stamp=%s WHERE Status=667676",(date))
         c.execute("UPDATE Counter_stamp SET Counter=%s WHERE Date_stamp=%s",(counter,date))
      db.commit()
      if rfid != '':
        try:
          c.execute("SELECT Attn FROM Member WHERE Id = %s",(rfid)) #Checking attendance of user
          attn=c.fetchone()[0]
          c.execute("SELECT Date_stamp FROM Member WHERE Id =%s",(rfid))#checking date of Member table
          attn_date=c.fetchone()[0]
          if date != attn_date:
             attn= attn +1
             c.execute("UPDATE Member SET Date_stamp=%s WHERE id=%s",(date,rfid))
             c.execute("UPDATE Member SET attn=%s WHERE id=%s",(attn,rfid))
             ser.write('z')
          db.commit()
          c.execute("SELECT Member_Name from Member WHERE Id=(%s)",(rfid))
          user = c.fetchone()[0]
          user=user.replace('\n','')
          rasp = open('/var/www/html/.web/message.txt','w')
          rasp.write("Hi "+user)
          rasp.close()
          time.sleep(1)
          rasp = open('/var/www/html/.web/message.txt','w')
          rasp.write("PROJECT MANAS")
          rasp.close()
        except :
         print ("Invalid Card")
         ser.write('y')
         rasp = open('/var/www/html/.web/message.txt','w')
         rasp.write("Invalid card ")
         rasp.close()
         time.sleep(1)
         rasp = open('/var/www/html/.web/message.txt','w')
         rasp.write("PROJECT MANAS")
         rasp.close()
      c.execute("SELECT Status FROM E_status WHERE Item = 'F1'")
      F1=c.fetchone()[0]
      if F1==0:
          ser.write('a')
      if F1==1:
          ser.write('b')
      c.execute("SELECT Status FROM E_status WHERE Item = 'F2'")
      F2=c.fetchone()[0]
      if F2==0:
          ser.write('c')
      if F2==1:
          ser.write('d')
      c.execute("SELECT Status FROM E_status WHERE Item = 'F3'")
      F3=c.fetchone()[0]
      if F3==0:
          ser.write('e')
      if F3==1:
          ser.write('f')
      c.execute("SELECT Status FROM E_status WHERE Item = 'L1'")
      L1=c.fetchone()[0]
      if L1==0:
          ser.write('g')
      if L1==1:
          ser.write('h')
      c.execute("SELECT Status FROM E_status WHERE Item = 'L2'")
      L2=c.fetchone()[0]
      if L2==0:
          ser.write('i')
      if L2==1:
          ser.write('j')
      c.execute("SELECT Status FROM E_status WHERE Item = 'L3'")
      L3=c.fetchone()[0]
      if L3==0:
          ser.write('k')
      if L3==1:
          ser.write('l')
      c.execute("SELECT Status FROM E_status WHERE Item = 'L4'")
      L4=c.fetchone()[0]
      if L4==0:
          ser.write('m')
      if L4==1:
          ser.write('n')
      c.execute("SELECT Status FROM E_status WHERE Item = 'L5'")
      L5=c.fetchone()[0]
      if L5==0:
          ser.write('o')
      if L5==1:
          ser.write('p')
      c.execute("SELECT Status FROM E_status WHERE Item = 'L6'")
      L6=c.fetchone()[0]
      if L6==0:
          ser.write('q')
      if L6==1:
          ser.write('r')
      c.execute("SELECT Status FROM E_status WHERE Item = 'L7'")
      L7=c.fetchone()[0]
      if L7==0:
          ser.write('s')
      if L7==1:
          ser.write('t')
      c.execute("SELECT Status FROM E_status WHERE Item = 'L8'")
      L8=c.fetchone()[0]
      if L8==0:
          ser.write('u')
      if L8==1:
           ser.write('v')
      c.execute("SELECT Status FROM E_status WHERE Item = 'L9'")
      L9=c.fetchone()[0]
      if L9==0:
          ser.write('w')
      if L9==1:
          ser.write('y')
