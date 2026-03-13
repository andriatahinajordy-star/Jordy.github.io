<?xml version="1.0" encoding="UTF-8"?>
<Algo>
    <description texte="" courant="FIN_POUR"/>
    <extension extnom="inactif"/>
    <fonction fctetat="inactif" fctcode=""/>
    <F2 F2etat="inactif" F2para="" F2defaut="" F2lignes=""/>
    <repere repetat="inactif" repcode="-10#10#-10#10#2#2"/>
    <param epaisseurPoint="2" maxBoucle="500000" totalBoucles="5000000" arrondiAuto="vrai" nbDecimales="8" totalAffichages="1000" epaisseurLigne="2"/>
    <item algoitem="FONCTIONS_UTILISEES" code="200#declarationfonctions"/>
    <item algoitem="VARIABLES" code="100#declarationsvariables">
        <item algoitem="n EST_DU_TYPE NOMBRE" code="1#NOMBRE#n"/>
        <item algoitem="i EST_DU_TYPE NOMBRE" code="1#NOMBRE#i"/>
        <item algoitem="T EST_DU_TYPE LISTE" code="1#LISTE#T"/>
        <item algoitem="s EST_DU_TYPE NOMBRE" code="1#NOMBRE#s"/>
        <item algoitem="m EST_DU_TYPE NOMBRE" code="1#NOMBRE#m"/>
        <item algoitem="min EST_DU_TYPE NOMBRE" code="1#NOMBRE#min"/>
        <item algoitem="max EST_DU_TYPE NOMBRE" code="1#NOMBRE#max"/>
        <item algoitem="posmin EST_DU_TYPE NOMBRE" code="1#NOMBRE#posmin"/>
        <item algoitem="posmax EST_DU_TYPE NOMBRE" code="1#NOMBRE#posmax"/>
        <item algoitem="temp EST_DU_TYPE NOMBRE" code="1#NOMBRE#temp"/>
        <item algoitem="j EST_DU_TYPE NOMBRE" code="1#NOMBRE#j"/>
    </item>
    <item algoitem="DEBUT_ALGORITHME" code="101#debutalgo">
        <item algoitem="AFFICHERCALCUL 12" code="20#12#0"/>
        <item algoitem="LIRE n" code="2#n#pasliste"/>
        <item algoitem="s PREND_LA_VALEUR 0" code="5#s#0#pasliste"/>
        <item algoitem="POUR i ALLANT_DE 1 A n" code="12#i#1#n">
            <item algoitem="DEBUT_POUR" code="13#debutpour"/>
            <item algoitem="AFFICHER i" code="3#i#0#pasliste"/>
            <item algoitem="LIRE T[i]" code="2#T#i"/>
            <item algoitem="s PREND_LA_VALEUR s + T[i]" code="5#s#s + T[i]#pasliste"/>
            <item algoitem="FIN_POUR" code="14#finpour"/>
        </item>
        <item algoitem="m PREND_LA_VALEUR s/n" code="5#m#s/n#pasliste"/>
        <item algoitem="min PREND_LA_VALEUR T[1]" code="5#min#T[1]#pasliste"/>
        <item algoitem="min PREND_LA_VALEUR T[1]" code="5#min#T[1]#pasliste"/>
        <item algoitem="posmin PREND_LA_VALEUR 1" code="5#posmin#1#pasliste"/>
        <item algoitem="posmax PREND_LA_VALEUR 1" code="5#posmax#1#pasliste"/>
        <item algoitem="" code="103#commentaire"/>
        <item algoitem="POUR i ALLANT_DE 2 A n" code="12#i#2#n">
            <item algoitem="DEBUT_POUR" code="13#debutpour"/>
            <item algoitem="AFFICHER i" code="3#i#0#pasliste"/>
            <item algoitem="SI (T[i] &lt; min) ALORS" code="6#T[i] &lt; min">
                <item algoitem="DEBUT_SI" code="7#debutsi"/>
                <item algoitem="AFFICHER min" code="3#min#0#pasliste"/>
                <item algoitem="min PREND_LA_VALEUR T[i]" code="5#min#T[i]#pasliste"/>
                <item algoitem="AFFICHER posmin" code="3#posmin#0#pasliste"/>
                <item algoitem="posmin PREND_LA_VALEUR i" code="5#posmin#i#pasliste"/>
                <item algoitem="FIN_SI" code="8#finsi"/>
            </item>
            <item algoitem="SI (T[i] > max) ALORS" code="6#T[i] > max">
                <item algoitem="DEBUT_SI" code="7#debutsi"/>
                <item algoitem="AFFICHER min" code="3#min#0#pasliste"/>
                <item algoitem="max PREND_LA_VALEUR T[i]" code="5#max#T[i]#pasliste"/>
                <item algoitem="AFFICHER max" code="3#max#0#pasliste"/>
                <item algoitem="posmax PREND_LA_VALEUR i" code="5#posmax#i#pasliste"/>
                <item algoitem="FIN_SI" code="8#finsi"/>
            </item>
            <item algoitem="AFFICHER s" code="3#s#0#pasliste"/>
            <item algoitem="AFFICHER m" code="3#m#0#pasliste"/>
            <item algoitem="AFFICHER min" code="3#min#0#pasliste"/>
            <item algoitem="AFFICHER posmin" code="3#posmin#0#pasliste"/>
            <item algoitem="AFFICHER max" code="3#max#0#pasliste"/>
            <item algoitem="AFFICHER posmax" code="3#posmax#0#pasliste"/>
            <item algoitem="FIN_POUR" code="14#finpour"/>
        </item>
        <item algoitem="" code="103#commentaire"/>
    </item>
    <item algoitem="FIN_ALGORITHME" code="102#finalgo"/>
</Algo>
