# Install the requests library in order to execute HTTP requests
# by running:       $ pip3 install requests

# Import the 'requests' and 'json' libraries to the script
import requests
import json


#       ╔═════════════════════════════════════════════╗
#       ║           Construct a FCM Message           ║
#       ╚═════════════════════════════════════════════╝

# Define the deviceID
deviceID = "test"

# Define the topic to publish the FCM message to
topic = "doorbell"

# Define the notification to be shown on the phone of the recipient
notification = {
  "title": "Fire Alarm - Take caution and leave the building!",
  "body": "Be careful there might be a fire. Leave the building immediately by the nearest exit! Contact emergencies.",
}

# Define the data payload to be passed onto the app
data_payload = {                  
    "title" : "Take caution and leave the building!",
    "content" : "Be careful there might be a fire. Leave the building immediately by the nearest exit! Contact emergencies.",
    "category" : "Fire Alarm",
    "author" : "Test_author"
}


#       ┌─────────────────────────────────────────────┐
#       │      Assemble and send the FCM Message      │
#       └─────────────────────────────────────────────┘

# The server token is the API key provided by Firebase
serverToken = 'AAAAKj2r-d0:APA91bEbp-oXiE9u7ubZjdvm2zJ8C_ZyCu-HnNACwiGRoRRip5GpRXBq7_v68zN-VQ4FP_tEsdkzj3SINnT6EBVN7NP9_VbfuVlN7y4x8x8z-uipPq_9upZTXyyrqik9Yh2mJKEBsj0o'

# Assemble the JSON data structures to be POSTed
# 1. define the request headers
headers = {
    'Content-Type': 'application/json',
    'Authorization': 'key=' + serverToken,
    }
# 2. define the request body
json_data = {
    'notification': notification,
    'to':  "/topics/" + deviceID + "_" + topic,
    'priority': 'high',
    'data': data_payload,
    }

# Send the HTTP POST request using the HTTP legacy API from Firebase (which allows for API keys)
# This is secure as 'requests' verifies the SSL 
response = requests.post("https://fcm.googleapis.com/fcm/send",headers = headers, data=json.dumps(json_data))


# Print the response from the server
#print("Response code from the server: \t\t" + str(response.status_code))
#print("Response message from the server: \t" + str(response.json()))