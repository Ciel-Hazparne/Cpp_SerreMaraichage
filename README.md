# Projet 2022 Serre de maraîchage connectée
**Flavio, développement C++/Arduino**
## Mission
Dans ce projet, il faut pouvoir récupérer les données de température et d’humidité de deux endroits différents.
- Le premier est une serre, dans laquelle un capteur de température et d’humidité placé sur une carte arduino envoie des données sur une deuxième carte arduino, via liaison LoRa.
- Le deuxième est un champ, dans lequel un capteur de température et d’humidité autonome envoie ces données sur le site d’Objenious via la liaison LoRaWan. La deuxième carte arduino doit ensuite récupérer ces données. Une fois toutes les données
récupérées, elles sont transmises via MQTT à un broker et à une API par une requête POST.
