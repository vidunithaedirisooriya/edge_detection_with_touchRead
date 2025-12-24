# Edge Detection with touchRead for touch toggle switches

 concept: when touched, the touchRead reads like this,
 touchRead value
     ^
 100 | _________ A             __________E
     |          \             /D
     |           \           /
     |____________\_________/_______________threshhold
     |           B \_______/C
  0  |_______________________________________>time

  AB=finger has just come into contact
  BC=finger is in contact
  CD=finger is lifting
  DE=finger not in contact

  therefore, if we count this trough (A to D) as one touch, we can do some toggling. 
  for now, the goal is to toggle the built in led by touching the pin touchPin