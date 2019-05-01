![Image](https://images.unsplash.com/photo-1501780392773-287d506245a5?auto=format&fit=crop&w=1950&q=80&ixid=dW5zcGxhc2guY29tOzs7Ozs%3D)

# Introduction
เนื่องจากปัจจุบันภัยคุกคามสามารถเกิดขึ้นได้ทุกสถานที่ ทุกเวลา นักศึกษาที่อาศัยหอพักจึงมีความเสี่ยงจากการถูกบุกรุก เราจึงเริ่มทำโปรเจคนี้ขึ้นเพื่อช่วยรักษาความปลอดภัยจากการเข้าถึงในสถานที่ต่างๆ เช่น หอพัก โรงพยาบาล โดยใช้ความรู้จากวิชา computer programming(ภาษา C, C# และ arduino) ออกมาเป็ประตูแบบผลักที่สามารถรักษาความปลอดภัย เมื่อกดรหัสที่ keypad ผิดเกิน 3 ครั้งจะส่งสัญญาณเตือนได้สองทางคือ การส่งสัญญาณเสียง(buzzer)และข้อความผ่านทางแอพพลิเคชั่น Line
# Required Components
| Arduino Uno  | 16X2 LCD | usb arduino |
|---------------|---------------|---------------|
|![Image](https://www.google.com/url?sa=i&source=images&cd=&cad=rja&uact=8&ved=2ahUKEwiliPGD0PrhAhWMPY8KHftnAo0QjRx6BAgBEAU&url=https%3A%2F%2Fwww.crazypi.com%2Farduino-uno-r3-microcontroller&psig=AOvVaw25CPb3XtbnJcA0_gtmjXJa&ust=1556810177002483|)|![Image](https://www.google.com/url?sa=i&source=images&cd=&cad=rja&uact=8&ved=2ahUKEwjTktHP0PrhAhVFKY8KHb-gAnsQjRx6BAgBEAU&url=http%3A%2F%2Fjebbush.co%2Fdisplay-lcd%2Fdisplay-lcd-display-lcd-16x2-backlight-azul-filipeflop%2F&psig=AOvVaw1vp-7xrrWUrymnOX7ey8iF&ust=1556810234540325)|![Image](https://www.google.com/url?sa=i&source=images&cd=&cad=rja&uact=8&ved=2ahUKEwjLxpz_0PrhAhUv7HMBHUm_DegQjRx6BAgBEAU&url=https%3A%2F%2Fwww.itead.cc%2Fusb-cable-type-a-to-type-b-50cm.html&psig=AOvVaw0oYxobeI-KT6rqGAtOcg2P&ust=1556810419637851)|

| nodemcu esp8266 | Breadboard | Wires |
|---------------|---------------|---------------|
|![Image](https://www.google.com/url?sa=i&source=images&cd=&cad=rja&uact=8&ved=2ahUKEwjK7_qW0_rhAhWEX3wKHVV9CI8QjRx6BAgBEAU&url=https%3A%2F%2Fwww.makerlab-electronics.com%2Fproduct%2Fnodemcu-v3-esp8266-esp-12e%2F&psig=AOvVaw18H8ckTUTWwMI4ZTnJeevF&ust=1556811031104518)|![Image](https://www.google.com/url?sa=i&source=images&cd=&cad=rja&uact=8&ved=2ahUKEwjb0um00_rhAhU9_XMBHepNAKoQjRx6BAgBEAU&url=https%3A%2F%2Fwww.sparkfun.com%2Fproducts%2F12615&psig=AOvVaw0Ihb7hPvsx_qtxh7Sz3zZi&ust=1556811087841989)|![Image](https://www.google.com/url?sa=i&source=images&cd=&cad=rja&uact=8&ved=2ahUKEwiCxLvY0_rhAhVl4HMBHXHjBTYQjRx6BAgBEAU&url=https%3A%2F%2Fwww.amazon.in%2FRobo-India-JW-C3-Jumper-Wire%2Fdp%2FB00YJ67SYW&psig=AOvVaw2pzUjsQ28M8kbeC2b4sPmf&ust=1556811123697471)|

| Potentiometer | Buzzer | nodemcu esp8266 |
|---------------|---------------|---------------|
|![Image](https://www.google.com/url?sa=i&source=images&cd=&cad=rja&uact=8&ved=2ahUKEwjews770_rhAhXYYysKHQNkBfkQjRx6BAgBEAU&url=https%3A%2F%2Fwww.sparkfun.com%2Fproducts%2F14624&psig=AOvVaw3pAjnB5brkZANUGyQ0Umh8&ust=1556811236407247)|![Image](https://www.google.com/url?sa=i&source=images&cd=&cad=rja&uact=8&ved=2ahUKEwiz0caU1PrhAhXFXCsKHQpHAwAQjRx6BAgBEAU&url=https%3A%2F%2Fmarket.samm.com%2Fbuzzer-en&psig=AOvVaw2Zg2QYDeteybfMgOL3IopK&ust=1556811270894950)|![Image]()|
