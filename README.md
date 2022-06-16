# PKDF2_HMAC512
Build component :
```
Dans le composant 3, on va tester la fonction PKDF2-HMAC512. Ce test se fait sur la base d’une chaine de test et voir que le hash est retourné pour HMAC avec en entrée sa clé, un message et son rang 512. Le résultat attendu est la validation du hash pour le même mot de passe.



cd PKDF2_HMAC512
make
```
Run tests :
```
cd components
python3 test.py
```
