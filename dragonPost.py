
# coding: utf-8

# # Send data to the server
# Probably using a get request to tell the server to increment 

# In[1]:


import serial, sys

ard = serial.Serial('/dev/tty96B0', 115200)


# In[5]:


import requests


# In[32]:


def checkPost(r):
    if r.status_code != 200:
        print("Error:", r.status_code, r.reason)


# In[31]:


def increment(clubID):
    r = requests.post("http://10.245.1.242:8000/entry/" + clubID, data={'number': 12524, 'type': 'issue', 'action': 'show'})
    checkPost(r)


# In[30]:


def decrement(clubID):
    r = requests.post("http://10.245.1.242:8000/leave/" + clubID, data={'number': 12524, 'type': 'issue', 'action': 'show'})
    checkPost(r)


# In[4]:


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: python3 dragonPost.py clubID=<clubID>")
        exit()
    clubID = sys.argv[1]
    if clubID == '0':
        print("Usage: make makefile clubID=<clubID>")
    print("Welcome to the Club Cracker! To quit, press CTRL + C")
    try:
        while True:
            ardOut = ard.readline()
            if ardOut.find("increment") != -1:
                increment(clubID)
            if ardOut.find("decrement") != -1:
                decrement(clubID)
    except KeyboardInterrupt:
        print("CTRL-C!! Exiting...")

