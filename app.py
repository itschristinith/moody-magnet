import os
from flask import Flask, request, render_template, jsonify
import requests
import serial

app = Flask(__name__)   # create our flask app

ser = serial.Serial('/dev/tty.usbmodemfa131', 9600) # set up serial

@app.route("/", methods=['GET', 'POST'])
def entertext():

	url = 'http://text-processing.com/api/sentiment/'

	if request.method == "POST":
		
		words = requests.post(url, {'text':request.form.get('text')})
		sentiPyData = words.json()

		if sentiPyData.get('label') == 'neg':
			ser.write('1')
			ser.close
		elif sentiPyData.get('label') == 'neutral':
			ser.write('3')
			ser.close
		else:
			ser.write('2')
			ser.close

		templateData = {
			'sentiment' : sentiPyData.get('label')
		}
		return render_template("sentiment.html", **templateData)
	else:
		return render_template("poetry.html")

if __name__ == "__main__":
	app.debug = True
	
	port = int(os.environ.get('PORT', 5000)) # locally PORT 5000, Heroku will assign its own port
	app.run(host='0.0.0.0', port=port)