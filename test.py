import cmc

from flask import Flask, jsonify
app = Flask(__name__)

@app.after_request
def after_request(response):
    response.headers.add('Access-Control-Allow-Origin', '*')
    response.headers.add('Access-Control-Allow-Headers', 'Content-Type,Authorization')
    response.headers.add('Access-Control-Allow-Methods', 'GET,PUT,POST,DELETE')
    return response

@app.route('/sidenav', methods = ['GET'])
def get_sidenav_info():
    response = jsonify({"clusterName": list(obj.providerNames)});
    return response

if __name__ == '__main__':
	app.run(debug=False, host='0.0.0.0')
#	time.sleep(4)
#	print(s)



