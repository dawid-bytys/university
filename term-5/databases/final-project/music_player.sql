-- MySQL dump 10.13  Distrib 8.2.0, for macos14.0 (arm64)
--
-- Host: localhost    Database: music_player
-- ------------------------------------------------------
-- Server version	8.2.0

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `albums`
--

DROP TABLE IF EXISTS `albums`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `albums` (
  `album_id` int NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `image` varchar(255) NOT NULL,
  `artist_id` int DEFAULT NULL,
  PRIMARY KEY (`album_id`),
  KEY `artist_id` (`artist_id`),
  CONSTRAINT `albums_ibfk_1` FOREIGN KEY (`artist_id`) REFERENCES `artists` (`artist_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `albums`
--

LOCK TABLES `albums` WRITE;
/*!40000 ALTER TABLE `albums` DISABLE KEYS */;
/*!40000 ALTER TABLE `albums` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `artists`
--

DROP TABLE IF EXISTS `artists`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `artists` (
  `artist_id` int NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `image` varchar(255) DEFAULT NULL,
  `monthly_listeners` int NOT NULL,
  `ranking` tinyint unsigned DEFAULT NULL,
  `bio` text,
  PRIMARY KEY (`artist_id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `artists`
--

LOCK TABLES `artists` WRITE;
/*!40000 ALTER TABLE `artists` DISABLE KEYS */;
INSERT INTO `artists` VALUES (1,'Playboi Carti','https://i.scdn.co/image/ab6761610000517473d4facbd619ae025b5588c7',40104442,73,'Atlanta rapper Playboi Carti debuted with a repetitive and catchy flow like contemporaries Lil Uzi Vert and Young Thug, gaining recognition in the mid-2010s as an affiliate of A$AP Mob. A steady succession of viral singles helped Carti\'s first proper album, 2018\'s Die Lit, debut at number three on the Billboard charts, and he moved into a new phase of his artistry with the riskier and more aggressive Whole Lotta Red in 2020.'),(2,'Yeat','https://i.scdn.co/image/ab67616100005174a36d13951ab8280a63bac16c',20632405,NULL,'Low-fi melodies, clever cutting lyrics, and a distinctly mysterious persona are all highlights that build up the enigma that is Yeat, one of the most interesting rises in music. The rapper broke through in 2021 when his song “Gët Busy” began appearing in TikTok videos. The track became so ubiquitous that it caught the attention of heavyweight rappers, including Drake, Lil Uzi Vert, Gunna, and many more. As his fame skyrocketed, so did the mania surrounding the artist’s cult-like following which led to the shutdown of a show in Los Angeles at The Roxy. Now, with two headlining tours under his belt, three Billboard Top 10 Album Debuts, and over 8 Billion global streams, the young talent is well on his way to superstardom.\n\nYeat was born Noah Smith in 2000. He began releasing music in 2015, taking notes from Young Thug’s melodic strangeness and the inventive production styles of rappers who were rising to prominence as he grew up. He started out using the moniker Lil Yeat, but changed it to Yeat in 2018. That year, he released his first mixtape, Deep Blue Strips. From then on, he was in hyperdrive. As his fame skyrocketed, Yeat released the mixtapes Alivë and 4L, and the Trëndi EP, before signing to Field Trip Recordings / Geffen Records for the release of his first proper studio album. Up 2 Më was issued in September 2021 followed by a second studio LP, 2 Alivë, in early 2022.\n\nRecently, he had his highest album debut to date with AftërLyfe at #4 on the Billboard 200 chart.'),(3,'Ken Carson','https://i.scdn.co/image/ab6761610000517495ccca370d8bd50e84c222bc',6388644,NULL,'In the Summer of 2021, Ken Carson released his full-length debut Project X, which marked a turning point in his career. For years, the Atlanta native sharpened his skills in melodic rap, culminating in a deal with Playboi Carti’s OPIUM Records/Interscope in 2019.  However, Ken has evolved rapidly in the past year and is testing new waters as he readies his next project.\nHaving made music since he was 13, the Atlanta native eventually cut his first track Geeked Up, which showed his promise as a burgeoning young act. In 2018 Ken began his talks with Playboi Carti, inking a deal with Carti’s OPIUM Records in 2019. As the pandemic raged into 2020, Ken took it as an opportunity to up the ante, releasing a series of EP’s, including Boy Barbie, Lost Files and Teen X, the latter of which featured “Yale,” which cracked 13.5 million streams on Spotify alone. Ken kept the momentum going into 2021, re-upping Teen X with Teen X: Relapsed, Lost Files 2, and his critically acclaimed debut album Project X, marking a gradual shift in Ken’s sound, tempering his signature melodic rap delivery with more lyrically driven songs that centered around storytelling. The album’s lead single Rock N Roll continues to make its rounds, as the music video is an electrifying psychedelic trip, complete with vivid animations and out of body experiences.\nKen is hard at work on his follow-up project, which he promises to pack with more experimentation, more evolution, and a chance to keep growing with his fans.'),(4,'Destroy Lonely','https://i.scdn.co/image/ab676161000051746003f54411b80a01d56a32cf',3336824,NULL,'Atlanta rapper Destroy Lonely typically delivers erratic, speedy rhymes over atmospheric trap beats. He\'s released numerous mixtapes and EPs since the late 2010s, and his 2019 single \"Bane\" became a viral hit two years after it first appeared. After signing with Playboi Carti\'s Opium  imprint, he issued the mixtape No Stylist in 2022, followed by his official full-length debut, If Looks Could Kill, in 2023.');
/*!40000 ALTER TABLE `artists` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `artists_concerts`
--

DROP TABLE IF EXISTS `artists_concerts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `artists_concerts` (
  `artist_id` int NOT NULL,
  `concert_id` int NOT NULL,
  KEY `artist_id` (`artist_id`),
  KEY `concert_id` (`concert_id`),
  CONSTRAINT `artists_concerts_ibfk_1` FOREIGN KEY (`artist_id`) REFERENCES `artists` (`artist_id`),
  CONSTRAINT `artists_concerts_ibfk_2` FOREIGN KEY (`concert_id`) REFERENCES `concerts` (`concert_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `artists_concerts`
--

LOCK TABLES `artists_concerts` WRITE;
/*!40000 ALTER TABLE `artists_concerts` DISABLE KEYS */;
/*!40000 ALTER TABLE `artists_concerts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `concerts`
--

DROP TABLE IF EXISTS `concerts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `concerts` (
  `concert_id` int NOT NULL AUTO_INCREMENT,
  `location` varchar(255) NOT NULL,
  `date` date NOT NULL,
  PRIMARY KEY (`concert_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `concerts`
--

LOCK TABLES `concerts` WRITE;
/*!40000 ALTER TABLE `concerts` DISABLE KEYS */;
/*!40000 ALTER TABLE `concerts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `playlists`
--

DROP TABLE IF EXISTS `playlists`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `playlists` (
  `playlist_id` int NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `description` text,
  `visibility` enum('public','private') NOT NULL,
  `user_id` int NOT NULL,
  PRIMARY KEY (`playlist_id`),
  KEY `user_id` (`user_id`),
  CONSTRAINT `playlists_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `users` (`user_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `playlists`
--

LOCK TABLES `playlists` WRITE;
/*!40000 ALTER TABLE `playlists` DISABLE KEYS */;
/*!40000 ALTER TABLE `playlists` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `subscriptions`
--

DROP TABLE IF EXISTS `subscriptions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `subscriptions` (
  `subscription_id` int NOT NULL AUTO_INCREMENT,
  `type` enum('free','student','family','normal') DEFAULT 'free',
  `expiration_date` date DEFAULT NULL,
  `user_id` int NOT NULL,
  PRIMARY KEY (`subscription_id`),
  KEY `fk_subscriptions_user` (`user_id`),
  CONSTRAINT `fk_subscriptions_user` FOREIGN KEY (`user_id`) REFERENCES `users` (`user_id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `subscriptions`
--

LOCK TABLES `subscriptions` WRITE;
/*!40000 ALTER TABLE `subscriptions` DISABLE KEYS */;
INSERT INTO `subscriptions` VALUES (1,'free',NULL,1);
/*!40000 ALTER TABLE `subscriptions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tracks`
--

DROP TABLE IF EXISTS `tracks`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tracks` (
  `track_id` int NOT NULL AUTO_INCREMENT,
  `title` varchar(255) NOT NULL,
  `url` varchar(255) NOT NULL,
  `streams` int DEFAULT NULL,
  `album_id` int DEFAULT NULL,
  PRIMARY KEY (`track_id`),
  KEY `album_id` (`album_id`),
  CONSTRAINT `tracks_ibfk_1` FOREIGN KEY (`album_id`) REFERENCES `albums` (`album_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tracks`
--

LOCK TABLES `tracks` WRITE;
/*!40000 ALTER TABLE `tracks` DISABLE KEYS */;
/*!40000 ALTER TABLE `tracks` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tracks_artists`
--

DROP TABLE IF EXISTS `tracks_artists`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tracks_artists` (
  `track_id` int NOT NULL,
  `artist_id` int NOT NULL,
  KEY `track_id` (`track_id`),
  KEY `artist_id` (`artist_id`),
  CONSTRAINT `tracks_artists_ibfk_1` FOREIGN KEY (`track_id`) REFERENCES `tracks` (`track_id`),
  CONSTRAINT `tracks_artists_ibfk_2` FOREIGN KEY (`artist_id`) REFERENCES `artists` (`artist_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tracks_artists`
--

LOCK TABLES `tracks_artists` WRITE;
/*!40000 ALTER TABLE `tracks_artists` DISABLE KEYS */;
/*!40000 ALTER TABLE `tracks_artists` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `users` (
  `user_id` int NOT NULL AUTO_INCREMENT,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `firstname` varchar(255) DEFAULT NULL,
  `lastname` varchar(255) DEFAULT NULL,
  `image` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`user_id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'dawidbytys','51f247e83f0915fc942b26a897eeea0930f73a0d7a441730f8aa480438f4afdc','dawid.bytys@proton.me','Dawid','Bytys',NULL);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `after_insert_user_add_subscription` AFTER INSERT ON `users` FOR EACH ROW BEGIN
    DECLARE new_subscription_id INT;
    DECLARE new_subscription_type VARCHAR(255);
    DECLARE new_expiration_date DATE;

    SET new_subscription_id = NULL;
    SET new_subscription_type = 'free';
    SET new_expiration_date = NULL;

    INSERT INTO subscriptions (subscription_id, user_id, type, expiration_date)
    VALUES (new_subscription_id, NEW.user_id, new_subscription_type, new_expiration_date);
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `users_liked_playlists`
--

DROP TABLE IF EXISTS `users_liked_playlists`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `users_liked_playlists` (
  `user_id` int NOT NULL,
  `playlist_id` int NOT NULL,
  KEY `user_id` (`user_id`),
  KEY `playlist_id` (`playlist_id`),
  CONSTRAINT `users_liked_playlists_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `users` (`user_id`),
  CONSTRAINT `users_liked_playlists_ibfk_2` FOREIGN KEY (`playlist_id`) REFERENCES `playlists` (`playlist_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users_liked_playlists`
--

LOCK TABLES `users_liked_playlists` WRITE;
/*!40000 ALTER TABLE `users_liked_playlists` DISABLE KEYS */;
/*!40000 ALTER TABLE `users_liked_playlists` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users_liked_tracks`
--

DROP TABLE IF EXISTS `users_liked_tracks`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `users_liked_tracks` (
  `user_id` int NOT NULL,
  `track_id` int NOT NULL,
  KEY `user_id` (`user_id`),
  KEY `track_id` (`track_id`),
  CONSTRAINT `users_liked_tracks_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `users` (`user_id`),
  CONSTRAINT `users_liked_tracks_ibfk_2` FOREIGN KEY (`track_id`) REFERENCES `tracks` (`track_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users_liked_tracks`
--

LOCK TABLES `users_liked_tracks` WRITE;
/*!40000 ALTER TABLE `users_liked_tracks` DISABLE KEYS */;
/*!40000 ALTER TABLE `users_liked_tracks` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'music_player'
--
/*!50003 DROP PROCEDURE IF EXISTS `AddArtist` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `AddArtist`(
    IN p_name VARCHAR(255),
    IN p_image VARCHAR(255),
    IN p_monthly_listeners INTEGER,
    IN p_ranking INTEGER,
    IN p_bio TEXT
)
BEGIN
    INSERT INTO artists (name, image, monthly_listeners, ranking, bio)
    VALUES (p_name, p_image, p_monthly_listeners, p_ranking, p_bio);
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `AddUser` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `AddUser`(
    IN p_username VARCHAR(255),
    IN p_password VARCHAR(255),
    IN p_email VARCHAR(255),
    IN p_firstname VARCHAR(255),
    IN p_lastname VARCHAR(255),
    IN p_image VARCHAR(255)
)
BEGIN
    INSERT INTO users (username, password, email, firstname, lastname, image)
    VALUES (p_username, p_password, p_email, p_firstname, p_lastname, p_image);
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-01-18 21:26:38
