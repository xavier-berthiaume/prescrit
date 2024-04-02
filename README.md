<h1>prescrit</h1>
<p>Un logiciel de gestion des prescriptions et des informations patient conçu par Xavier Berthiaume.</p>

<h2>Plus sur ce projet</h2>
<p>Le but de <i>prescrit</i> est d'être une collection de logiciels open source qui facilitent la tâche à des pharmacies de petite taille de faire la gestion des informations patients.
Les logiciels comprit y sont un serveur qui peut être déployé en utilisant son contenant Docker, un client mobile et desktop, et une appli web écrit en React.</p>

<h1>Installation</h1>
<h2>Serveur</h2>
<p>À Venir</p>

<h2>Client</h2>
<p>À Venir</p>

<h2>Deployer l'Appli Web</h2>
<p>À Venir</p>

<h2>Library pour le dévéloppement</h2>
<p>Le dossier <code>/lib</code> du projet contient tout le code qui supporte les différentes applications qui composent le projet <i>prescrit</i> et peuvent être installés et bâti. Pour bâtir cette library
il ne suffit que de clôner le repo, créer un dossier <code>/build</code>, et utiliser cmake pour créer le makefile. Si vous souhaitez bâtir les unit tests, ajouter le flag <code>-DBUILD_TESTS=ON</code> à la commande cmake.
</p>
