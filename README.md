raspberry-cam
=============
Donc pas de SSH.

Heurement Github est grand, Github est beau, et Github accepte les push via HTTPS.

Modifiez juste une ligne dans votre fichier .git/config de :

[remote "origin"]
	url = git@github.com/votre_pseudo/votre_repo.git

Vers :

[remote "origin"]
	url = https://github.com/votre_pseudo/votre_repo.git

La commande git devrait vous prompter pour username (mettez votre email) et mot de passe, et hop : le monde du télétravail à la campagne s’ouvre à vous.

Note : Du coup tu met mon adresse et mon depo, normalement tu devrais pouvoir pusher si je t'ajoute en collaborateur
Et pour le username, ton ID passe je crois
