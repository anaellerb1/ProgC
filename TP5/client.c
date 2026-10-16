/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "client.h"

/**
 * Envoie une demande de calcul au serveur au format
 * "calcule : <op> <nombre1> <nombre2>", puis affiche la réponse.
 * @param socketfd Le descripteur de la socket.
 * @param op L'opérateur (+, -, *, /).
 * @param a Le premier nombre.
 * @param b Le deuxième nombre.
 * @return 0 en cas de succès, -1 en cas d'erreur.
 */
int envoie_operateur_numeros(int socketfd, char op, double a, double b)
{
  char data[1024];

  // Construire le message : "calcule : + 23 45"
  snprintf(data, sizeof(data), "calcule : %c %g %g", op, a, b);

  // Envoyer le message au serveur
  int write_status = write(socketfd, data, strlen(data));
  if (write_status < 0)
  {
    perror("Erreur d'écriture");
    return -1;
  }

  // Lire la réponse du serveur (on garde une case pour le '\0')
  memset(data, 0, sizeof(data));
  int read_status = read(socketfd, data, sizeof(data) - 1);
  if (read_status < 0)
  {
    perror("Erreur de lecture");
    return -1;
  }

  printf("Message reçu: %s\n", data);
  return 0;
}

/**
 * Fonction pour envoyer et recevoir un message depuis un client connecté à la socket.
 *
 * @param socketfd Le descripteur de la socket utilisée pour la communication.
 * @return 0 en cas de succès, -1 en cas d'erreur.
 */
int envoie_recois_message(int socketfd)
{
  char data[1024];

  // Réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // Demande à l'utilisateur d'entrer un message
  char message[1024];
  printf("Votre message (max 1000 caractères): ");
  fgets(message, sizeof(message), stdin);

  // Demande de calcul : l'utilisateur a tapé "calcule : <op> <nombre1> <nombre2>"
  if (strncmp(message, "calcule", 7) == 0)
  {
    char op;
    double a, b;
    char reste;

    // Format correct (exactement 3 valeurs) : on passe par envoie_operateur_numeros
    if (sscanf(message, "calcule : %c %lf %lf %c", &op, &a, &b, &reste) == 3)
    {
      return envoie_operateur_numeros(socketfd, op, a, b);
    }

    // Format incorrect : on envoie le texte tel quel, le serveur répondra par une erreur
    strcpy(data, message);
  }
  else
  {
    // Construit le message avec une étiquette "message: "
    strcpy(data, "message: ");
    strcat(data, message);
  }

  // Envoie le message au client
  int write_status = write(socketfd, data, strlen(data));
  if (write_status < 0)
  {
    perror("Erreur d'écriture");
    return -1;
  }

  // Réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // Lit les données de la socket
  int read_status = read(socketfd, data, sizeof(data));
  if (read_status < 0)
  {
    perror("Erreur de lecture");
    return -1;
  }

  // Affiche le message reçu du client
  printf("Message reçu: %s\n", data);

  return 0; // Succès
}

int main()
{
  int socketfd;

  struct sockaddr_in server_addr;

  /*
   * Creation d'une socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd < 0)
  {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // demande de connection au serveur
  int connect_status = connect(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (connect_status < 0)
  {
    perror("connection serveur");
    exit(EXIT_FAILURE);
  }

  while (1)
  {
    // appeler la fonction pour envoyer un message au serveur
    envoie_recois_message(socketfd);
  }

  close(socketfd);
}