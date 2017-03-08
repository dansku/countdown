#calculate time differnece
import time
import os

while True:

	now = time.time() #1488997525
	end = 1517504400

	difference = end - now

	if difference > 0:

		days 	= int(difference / 86400)
		hours 	= int((difference - (days * 60 * 60 * 24))/(60*60))
		minutes = int((difference - (days * 60 * 60 * 24) - (hours * 60 * 60 ))/60)
		seconds = int(difference - (days * 60 * 60 * 24) - (hours * 60 * 60 ) - (minutes * 60))

		print str(days) + " " + str(hours)+":"+str(minutes)+":"+str(seconds)

	else:
		print "666 66:66:66"

	time.sleep(0.1)
	os.system('cls')