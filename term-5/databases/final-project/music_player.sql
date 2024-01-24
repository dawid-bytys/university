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
-- Current Database: `music_player`
--

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `music_player` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;

USE `music_player`;

--
-- Temporary view structure for view `album_tracks_view`
--

DROP TABLE IF EXISTS `album_tracks_view`;
/*!50001 DROP VIEW IF EXISTS `album_tracks_view`*/;
SET @saved_cs_client     = @@character_set_client;
/*!50503 SET character_set_client = utf8mb4 */;
/*!50001 CREATE VIEW `album_tracks_view` AS SELECT 
 1 AS `album_id`,
 1 AS `album_name`,
 1 AS `tracks`*/;
SET character_set_client = @saved_cs_client;

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
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `albums`
--

LOCK TABLES `albums` WRITE;
/*!40000 ALTER TABLE `albums` DISABLE KEYS */;
INSERT INTO `albums` VALUES (1,'Whole Lotta Red','https://i.scdn.co/image/ab67616d00001e0298ea0e689c91f8fea726d9bb',1),(2,'Die Lit','https://i.scdn.co/image/ab67616d00001e02a1e867d40e7bb29ced5c0194',1),(3,'Playboi Carti','https://i.scdn.co/image/ab67616d00001e02e31a279d267f3b3d8912e6f1',1),(4,'In Abundance','https://i.scdn.co/image/ab67616d00001e02e6778eb47c6b217e4412850d',1),(5,'Lyfë','https://i.scdn.co/image/ab67616d00001e027aee5b36a3a60ca926bc429b',2),(6,'Up 2 Më','https://i.scdn.co/image/ab67616d00001e027f18c4658caa4a3d47f2d978',2),(7,'AftërLyfe','https://i.scdn.co/image/ab67616d00001e023f560650c583444498c214f0',2),(8,'2 Alivë','https://i.scdn.co/image/ab67616d00001e0272b69f1f356613717909d6db',2),(9,'UTOPIA','https://i.scdn.co/image/ab67616d00001e02881d8d8378cd01099babcd44',9),(10,'Birds In The Trap Sing McKnight','https://i.scdn.co/image/ab67616d00001e02f54b99bf27cda88f4a7403ce',9);
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
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `artists`
--

LOCK TABLES `artists` WRITE;
/*!40000 ALTER TABLE `artists` DISABLE KEYS */;
INSERT INTO `artists` VALUES (1,'Playboi Carti','https://i.scdn.co/image/ab6761610000517473d4facbd619ae025b5588c7',40104442,73,'Atlanta rapper Playboi Carti debuted with a repetitive and catchy flow like contemporaries Lil Uzi Vert and Young Thug, gaining recognition in the mid-2010s as an affiliate of A$AP Mob. A steady succession of viral singles helped Carti\'s first proper album, 2018\'s Die Lit, debut at number three on the Billboard charts, and he moved into a new phase of his artistry with the riskier and more aggressive Whole Lotta Red in 2020.'),(2,'Yeat','https://i.scdn.co/image/ab67616100005174a36d13951ab8280a63bac16c',20632405,NULL,'Low-fi melodies, clever cutting lyrics, and a distinctly mysterious persona are all highlights that build up the enigma that is Yeat, one of the most interesting rises in music. The rapper broke through in 2021 when his song “Gët Busy” began appearing in TikTok videos. The track became so ubiquitous that it caught the attention of heavyweight rappers, including Drake, Lil Uzi Vert, Gunna, and many more. As his fame skyrocketed, so did the mania surrounding the artist’s cult-like following which led to the shutdown of a show in Los Angeles at The Roxy. Now, with two headlining tours under his belt, three Billboard Top 10 Album Debuts, and over 8 Billion global streams, the young talent is well on his way to superstardom.\n\nYeat was born Noah Smith in 2000. He began releasing music in 2015, taking notes from Young Thug’s melodic strangeness and the inventive production styles of rappers who were rising to prominence as he grew up. He started out using the moniker Lil Yeat, but changed it to Yeat in 2018. That year, he released his first mixtape, Deep Blue Strips. From then on, he was in hyperdrive. As his fame skyrocketed, Yeat released the mixtapes Alivë and 4L, and the Trëndi EP, before signing to Field Trip Recordings / Geffen Records for the release of his first proper studio album. Up 2 Më was issued in September 2021 followed by a second studio LP, 2 Alivë, in early 2022.\n\nRecently, he had his highest album debut to date with AftërLyfe at #4 on the Billboard 200 chart.'),(3,'Ken Carson','https://i.scdn.co/image/ab6761610000517495ccca370d8bd50e84c222bc',6388644,NULL,'In the Summer of 2021, Ken Carson released his full-length debut Project X, which marked a turning point in his career. For years, the Atlanta native sharpened his skills in melodic rap, culminating in a deal with Playboi Carti’s OPIUM Records/Interscope in 2019.  However, Ken has evolved rapidly in the past year and is testing new waters as he readies his next project.\nHaving made music since he was 13, the Atlanta native eventually cut his first track Geeked Up, which showed his promise as a burgeoning young act. In 2018 Ken began his talks with Playboi Carti, inking a deal with Carti’s OPIUM Records in 2019. As the pandemic raged into 2020, Ken took it as an opportunity to up the ante, releasing a series of EP’s, including Boy Barbie, Lost Files and Teen X, the latter of which featured “Yale,” which cracked 13.5 million streams on Spotify alone. Ken kept the momentum going into 2021, re-upping Teen X with Teen X: Relapsed, Lost Files 2, and his critically acclaimed debut album Project X, marking a gradual shift in Ken’s sound, tempering his signature melodic rap delivery with more lyrically driven songs that centered around storytelling. The album’s lead single Rock N Roll continues to make its rounds, as the music video is an electrifying psychedelic trip, complete with vivid animations and out of body experiences.\nKen is hard at work on his follow-up project, which he promises to pack with more experimentation, more evolution, and a chance to keep growing with his fans.'),(4,'Destroy Lonely','https://i.scdn.co/image/ab676161000051746003f54411b80a01d56a32cf',3336824,NULL,'Atlanta rapper Destroy Lonely typically delivers erratic, speedy rhymes over atmospheric trap beats. He\'s released numerous mixtapes and EPs since the late 2010s, and his 2019 single \"Bane\" became a viral hit two years after it first appeared. After signing with Playboi Carti\'s Opium  imprint, he issued the mixtape No Stylist in 2022, followed by his official full-length debut, If Looks Could Kill, in 2023.'),(5,'Kendrick Lamar','https://i.scdn.co/image/ab67616100005174437b9e2a82505b3d93ff1022',51142049,44,'Kendrick Lamar\'s compelling lyricism, virtuosic microphone command, and sharp conceptual vision have translated to a rare combination of continuous chart feats and critical acclaim, plus respect and support from the artists who paved the way for the rapper\'s advancement. The Compton MC started as a teen in the early 2000s and hit his creative and commercial stride the next decade. The proper albums Lamar released by the end of the 2010s, namely the breakthrough good kid, m.A.A.d city (2012), Grammy-winning To Pimp a Butterfly (2015), and Grammy- and Pulitzer Prize-winning DAMN. (2017), displayed an unmatched mix of inventive wordplay and riveting narratives with assertion of artistic dominance, examination of internal conflict, and upliftment of community all centered. Remarkably, those qualities were exemplified in their Top 40 singles, including \"Swimming Pools (Drank),\" \"i,\" and the number one hit \"HUMBLE.\" among a total of seven the albums produced.'),(6,'Metro Boomin','https://i.scdn.co/image/ab67616100005174df9a1555f53a20087b8c5a5c',52473130,42,'St. Louis-raised, Atlanta-based producer Metro Boomin is the master of a street-oriented sound that is jet-black and low-gloss, sufficiently reflected in his alias.'),(7,'Kanye West','https://i.scdn.co/image/ab67616100005174867008a971fae0f4d913f63a',63990393,18,'Ty Dolla $ign  to form new project ¥$, the duo working towards the release of their debut album Vultures.A proud and vocal Chicagoan, West was actually born in Atlanta, moving to the Windy City with his English professor mother after his parents split when he was three years old. One of his major inspirations, Donda West helped shape young Kanye, taking him to China in the late \'80s on education exchange and establishing a strong base that made him a top pupil in high school. However, his music dreams would eventually eclipse academics and he dropped out of college, setting the stage for his best-selling school trilogy. With guidance from local producer No I.D., West went on to learn the finer points of studio production, programming, and sampling, the latter technique becoming a hallmark of his early work.He first got his foot in the industry door in the late \'90s, doing quite a bit of noteworthy production work for the likes of  to form new project ¥$, the duo working towards the release of their debut album Vultures.A proud and vocal Chicagoan, West was actually born in Atlanta, moving to the Windy City with his English professor mother after his parents split when he was three years old. One of his major inspirations, Donda West helped shape young Kanye, taking him to China in the late \'80s on education exchange and establishing a strong base that made him a top pupil in high school. However, his music dreams would eventually eclipse academics and he dropped out of college, setting the stage for his best-selling school trilogy. With guidance from local producer No I.D., West went on to learn the finer points of studio production, programming, and sampling, the latter technique becoming a hallmark of his early work.He first got his foot in the industry door in the late \'90s, doing quite a bit of noteworthy production work for the likes of One of the most influential, critically-lauded, and controversial artists of the early 21st century, American rapper and producer Kanye West has gone from hip-hop beatmaker to worldwide hitmaker with a wildly successful solo career that counted an unbroken string of chart-topping, multi-platinum albums and nearly two-dozen Grammy Awards. His early 2000s production work quickly led to a major-label recording contract, yielding a classic trilogy comprised of 2004\'s The College Dropout, 2005\'s Late Registration, and 2007\'s Graduation. With each successive album, he pushed the boundaries of hip-hop and soon entered a new phase of artistry with game changers such as 2008\'s 808s & Heartbreak, 2010\'s widely-regarded magnum opus My Beautiful Dark Twisted Fantasy, and 2013\'s industrial-leaning foray Yeezus. Celebrity, tabloid headlines, and a changing artistic vision informed much of his next era, as the trappings of fame and inner turmoil became the focus of chart-toppers such as The Life of Pablo and Ye. He even released a gospel album, Jesus Is King, in 2019. As his outspoken personality and political statements began to eclipse his music into the 2020s, he still managed to top the charts and garner accolades with 2020\'s exploratory Donda. In 2023, West joined forces with Jermaine Dupri.'),(8,'Future','https://i.scdn.co/image/ab6761610000517424e41f491b129093a6fee383',51167210,44,'Known for a uniquely fluid and melodic yet mumbling vocal style, Future busted out of the South at the dawn of the 2010s with a flurry of mixtapes, high-charting albums, certified platinum singles, and contributions to several other hits as a featured artist, then continued to hover at the top of his game, both commercially and creatively, in the years that followed. After he scored his first hit via a guest spot on YC.'),(9,'Travis Scott','https://i.scdn.co/image/ab6761610000517419c2790744c792d05570bb71',63569270,19,'Houston-born rapper and producer Travis Scotts psychedelic trap style makes him one of the more distinctive talents to have risen to the height of mainstream commercial popularity. His heavily processed, half-sung/half-rapped style set him apart early on, and he grew from affiliations.'),(10,'Homixide Gang','https://i.scdn.co/image/ab6761610000517437f3b59d4e544a0da5a42e76',1539114,NULL,'#FreeProblem #FreeDemon');
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
INSERT INTO `artists_concerts` VALUES (1,4),(9,1),(9,2),(9,3),(10,4);
/*!40000 ALTER TABLE `artists_concerts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Temporary view structure for view `concert_details_view`
--

DROP TABLE IF EXISTS `concert_details_view`;
/*!50001 DROP VIEW IF EXISTS `concert_details_view`*/;
SET @saved_cs_client     = @@character_set_client;
/*!50503 SET character_set_client = utf8mb4 */;
/*!50001 CREATE VIEW `concert_details_view` AS SELECT 
 1 AS `concert_id`,
 1 AS `location`,
 1 AS `date`,
 1 AS `artist_names`*/;
SET character_set_client = @saved_cs_client;

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
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `concerts`
--

LOCK TABLES `concerts` WRITE;
/*!40000 ALTER TABLE `concerts` DISABLE KEYS */;
INSERT INTO `concerts` VALUES (1,'Kaseya Center','2024-01-28'),(2,'Kia Center','2024-01-31'),(3,'KFC Yum! Center','2024-02-05'),(4,'United Center','2024-02-12');
/*!40000 ALTER TABLE `concerts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Temporary view structure for view `playlist_details_view`
--

DROP TABLE IF EXISTS `playlist_details_view`;
/*!50001 DROP VIEW IF EXISTS `playlist_details_view`*/;
SET @saved_cs_client     = @@character_set_client;
/*!50503 SET character_set_client = utf8mb4 */;
/*!50001 CREATE VIEW `playlist_details_view` AS SELECT 
 1 AS `playlist_id`,
 1 AS `playlist_name`,
 1 AS `playlist_description`,
 1 AS `visibility`,
 1 AS `user_id`,
 1 AS `tracks`*/;
SET character_set_client = @saved_cs_client;

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
  `tracks_count` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`playlist_id`),
  KEY `user_id` (`user_id`),
  CONSTRAINT `playlists_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `users` (`user_id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `playlists`
--

LOCK TABLES `playlists` WRITE;
/*!40000 ALTER TABLE `playlists` DISABLE KEYS */;
INSERT INTO `playlists` VALUES (1,'late night studying',NULL,'public',1,4),(2,'car ride','we drivin','private',2,5),(3,'gaming',NULL,'private',3,4);
/*!40000 ALTER TABLE `playlists` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `playlists_tracks`
--

DROP TABLE IF EXISTS `playlists_tracks`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `playlists_tracks` (
  `playlist_id` int NOT NULL,
  `track_id` int NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `playlists_tracks`
--

LOCK TABLES `playlists_tracks` WRITE;
/*!40000 ALTER TABLE `playlists_tracks` DISABLE KEYS */;
INSERT INTO `playlists_tracks` VALUES (1,1),(1,3),(1,6),(1,8),(2,1),(2,10),(2,11),(2,12),(3,1),(3,3),(3,8),(3,13),(2,13);
/*!40000 ALTER TABLE `playlists_tracks` ENABLE KEYS */;
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
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `after_insert_playlists_tracks` AFTER INSERT ON `playlists_tracks` FOR EACH ROW BEGIN
    UPDATE playlists
    SET tracks_count = (SELECT COUNT(*) FROM playlists_tracks WHERE playlist_id = NEW.playlist_id)
    WHERE playlist_id = NEW.playlist_id;
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `after_delete_playlists_tracks` AFTER INSERT ON `playlists_tracks` FOR EACH ROW BEGIN
    UPDATE playlists
    SET tracks_count = (SELECT COUNT(*) FROM playlists_tracks WHERE playlist_id = NEW.playlist_id)
    WHERE playlist_id = NEW.playlist_id;
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

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
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `subscriptions`
--

LOCK TABLES `subscriptions` WRITE;
/*!40000 ALTER TABLE `subscriptions` DISABLE KEYS */;
INSERT INTO `subscriptions` VALUES (1,'free',NULL,1),(2,'free',NULL,2),(3,'normal','2024-01-29',3),(4,'free',NULL,4),(5,'free',NULL,5),(6,'free',NULL,6),(7,'family','2024-02-20',7),(8,'free',NULL,8),(9,'student','2024-04-11',9),(10,'free',NULL,10);
/*!40000 ALTER TABLE `subscriptions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Temporary view structure for view `track_artists_view`
--

DROP TABLE IF EXISTS `track_artists_view`;
/*!50001 DROP VIEW IF EXISTS `track_artists_view`*/;
SET @saved_cs_client     = @@character_set_client;
/*!50503 SET character_set_client = utf8mb4 */;
/*!50001 CREATE VIEW `track_artists_view` AS SELECT 
 1 AS `track_id`,
 1 AS `track_title`,
 1 AS `artists`*/;
SET character_set_client = @saved_cs_client;

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
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tracks`
--

LOCK TABLES `tracks` WRITE;
/*!40000 ALTER TABLE `tracks` DISABLE KEYS */;
INSERT INTO `tracks` VALUES (1,'Rockstar Made','https://open.spotify.com/track/3cWmqvMwVQKDigWLSZ3w9h?si=56ecdc94fa394579',124970096,1),(2,'Go2DaMoon (feat. Kanye West)','https://open.spotify.com/track/0F13K9dwYH2zpTWiR8d628?si=14e44be3233f401d',103921737,1),(3,'Stop Breathing','https://open.spotify.com/track/2lLG56qpLP3UbcLuzMvkWX?si=87d72155164745f3',156128674,1),(4,'Beno!','https://open.spotify.com/track/4CYTQpr2jc4uBScYvpEK2w?si=f80e681190c5445f',47720717,1),(5,'Teen X (feat. Future)','https://open.spotify.com/track/5uYqmEN6TAAE8ss8YmprNV?si=f6e074a1fbe7478f',39206368,1),(6,'Vamp Anthem','https://open.spotify.com/track/4CzhtKifG867Lu5DNQVBSA?si=409a579d9b034902',253732651,1),(7,'Sky','https://open.spotify.com/track/29TPjc8wxfz4XMn21O7VsZ?si=c4623443ffc04a29',622077683,1),(8,'FE!N (feat. Playboi Carti)','https://open.spotify.com/track/42VsgItocQwOQC3XWZ8JNA?si=8232facce1dc4b36',290204534,9),(9,'through the late night','https://open.spotify.com/track/1Ci4wASMY4xtKVMeHA6Sd5?si=98327e5d895c4202',256544223,10),(10,'the ends','https://open.spotify.com/track/33zbOXJSwW7uf4VXXWow2O?si=522e10751a1447ce',105468266,10),(11,'way back','https://open.spotify.com/track/2Zy7XVdxyZQB8xp5xbpJdl?si=6f6f8638d5a142d2',161298047,10),(12,'sdp interlude','https://open.spotify.com/track/4gh0ZnHzaTMT1sDga7Ek0N?si=3f546f0fa0ed4066',269803219,10),(13,'beibs in the trap','https://open.spotify.com/track/0ESJlaM8CE1jRWaNtwSNj8?si=bc4194a8fda84cb9',403719146,10);
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
  `feat` tinyint(1) NOT NULL,
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
INSERT INTO `tracks_artists` VALUES (1,1,0),(2,1,0),(3,1,0),(4,1,0),(5,1,0),(6,1,0),(7,1,0),(2,7,1),(5,8,1),(8,9,0),(8,1,1),(9,9,0),(10,9,0),(11,9,0),(12,9,0),(13,9,0);
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
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'dawid_bytys','51f247e83f0915fc942b26a897eeea0930f73a0d7a441730f8aa480438f4afdc','dawid.bytys@proton.me','Dawid','Bytys',NULL),(2,'john_doe','5e884898da28047151d0e56f8dc6292773603d0d6aabbdd62a11ef721d1542d8','john.doe@email.com','John','Doe','https://example.com/john_doe.jpg'),(3,'jane_smith','c3801d4e4ed9de491ed52a5b98bcfd5d9d0ba04d476ab177a96a530882e20fe3','jane.smith@email.com','Jane','Smith','https://example.com/jane_smith.jpg'),(4,'bob_johnson','d9aeeecebd5329b898c3e21b7a07c19bb7c99d0dce69dddb10353d8d16f192d8','bob.johnson@email.com','Bob','Johnson','https://example.com/bob_johnson.jpg'),(5,'alice_williams','f5ea6973a3a72b4a9575d64794290f89397b4a4c02cf6aa8b38e70c0e50b4a5b','alice.williams@email.com','Alice','Williams','https://example.com/alice_williams.jpg'),(6,'charlie_brown','a152b8c5b84e64a3e0e9a3f3eeb5e4f2e5b9295c174b9d982e2f9a3c0f3a5d2d','charlie.brown@email.com','Charlie','Brown','https://example.com/charlie_brown.jpg'),(7,'eva_miller','c1cfeda5ee3e373b57e2a63d58b0dd7d0b82877f50f073070b862f3f7337fb2d','eva.miller@email.com','Eva','Miller','https://example.com/eva_miller.jpg'),(8,'david_jones','9a7e3ffdc9e74d70207b957a1a7732722d09f8a0f25596c38df0eabe7d42342b','david.jones@email.com','David','Jones','https://example.com/david_jones.jpg'),(9,'sophie_clark','86c2c99cc2584be9d1502e10d6a27e240b4b9673dd82b76f9916e570367888e4','sophie.clark@email.com','Sophie','Clark','https://example.com/sophie_clark.jpg'),(10,'michael_taylor','14690cc61d3e946ba2bb37932e2258a05d11d794227bc34881ba9c8c1a6e6c8f','michael.taylor@email.com','Michael','Taylor','https://example.com/michael_taylor.jpg');
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
-- Dumping routines for database 'music_player'
--
/*!50003 DROP PROCEDURE IF EXISTS `AddAlbum` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `AddAlbum`(IN p_name varchar(255), IN p_image varchar(255),
                                                 p_artist_id INTEGER)
BEGIN
    INSERT INTO albums (name, image, artist_id)
    VALUES (p_name, p_image, p_artist_id);
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
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
/*!50003 DROP PROCEDURE IF EXISTS `AddPlaylist` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `AddPlaylist`(
    IN p_name VARCHAR(255),
    IN p_description TEXT,
    IN p_visibility ENUM('private', 'public'),
    IN p_user_id INT
)
BEGIN
    DECLARE v_playlist_id INT;

    INSERT INTO playlists(name, description, visibility, user_id)
    VALUES (p_name, p_description, p_visibility, p_user_id);

    SET v_playlist_id = LAST_INSERT_ID();

    SELECT v_playlist_id AS playlist_id;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `AddTrack` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `AddTrack`(IN p_title varchar(255), IN p_url varchar(255),
                                                 IN p_streams int, IN p_album_id int)
BEGIN
    INSERT INTO tracks (title, url, streams, album_id)
    VALUES (p_title, p_url, p_streams, p_album_id);
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
/*!50003 DROP PROCEDURE IF EXISTS `ShowTriggers` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `ShowTriggers`()
BEGIN
    SELECT
        TRIGGER_NAME,
        EVENT_MANIPULATION,
        EVENT_OBJECT_TABLE,
        ACTION_TIMING,
        ACTION_STATEMENT
    FROM
        information_schema.TRIGGERS
    WHERE
        TRIGGER_SCHEMA = 'music_player';
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `UpdateSubscription` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `UpdateSubscription`(
    IN p_user_id INTEGER,
    IN p_type VARCHAR(255),
    IN p_expiration_date DATE
)
BEGIN
    UPDATE subscriptions
    SET type = p_type, expiration_date = p_expiration_date
    WHERE user_id = p_user_id;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Current Database: `music_player`
--

USE `music_player`;

--
-- Final view structure for view `album_tracks_view`
--

/*!50001 DROP VIEW IF EXISTS `album_tracks_view`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8mb4 */;
/*!50001 SET character_set_results     = utf8mb4 */;
/*!50001 SET collation_connection      = utf8mb4_0900_ai_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `album_tracks_view` AS select `a`.`album_id` AS `album_id`,`a`.`name` AS `album_name`,group_concat(`t`.`title` order by `t`.`track_id` ASC separator ', ') AS `tracks` from (`albums` `a` join `tracks` `t` on((`a`.`album_id` = `t`.`album_id`))) group by `a`.`album_id`,`a`.`name` */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;

--
-- Final view structure for view `concert_details_view`
--

/*!50001 DROP VIEW IF EXISTS `concert_details_view`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8mb4 */;
/*!50001 SET character_set_results     = utf8mb4 */;
/*!50001 SET collation_connection      = utf8mb4_0900_ai_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `concert_details_view` AS select `c`.`concert_id` AS `concert_id`,`c`.`location` AS `location`,`c`.`date` AS `date`,group_concat(`a`.`name` order by `a`.`name` ASC separator ', ') AS `artist_names` from ((`concerts` `c` join `artists_concerts` `ac` on((`c`.`concert_id` = `ac`.`concert_id`))) join `artists` `a` on((`ac`.`artist_id` = `a`.`artist_id`))) group by `c`.`concert_id`,`c`.`location`,`c`.`date` */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;

--
-- Final view structure for view `playlist_details_view`
--

/*!50001 DROP VIEW IF EXISTS `playlist_details_view`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8mb4 */;
/*!50001 SET character_set_results     = utf8mb4 */;
/*!50001 SET collation_connection      = utf8mb4_0900_ai_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `playlist_details_view` AS select `p`.`playlist_id` AS `playlist_id`,`p`.`name` AS `playlist_name`,`p`.`description` AS `playlist_description`,`p`.`visibility` AS `visibility`,`p`.`user_id` AS `user_id`,group_concat(`t`.`title` order by `pt`.`track_id` ASC separator ', ') AS `tracks` from ((`playlists` `p` join `playlists_tracks` `pt` on((`p`.`playlist_id` = `pt`.`playlist_id`))) join `tracks` `t` on((`pt`.`track_id` = `t`.`track_id`))) group by `p`.`playlist_id` */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;

--
-- Final view structure for view `track_artists_view`
--

/*!50001 DROP VIEW IF EXISTS `track_artists_view`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8mb4 */;
/*!50001 SET character_set_results     = utf8mb4 */;
/*!50001 SET collation_connection      = utf8mb4_0900_ai_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `track_artists_view` AS select `t`.`track_id` AS `track_id`,`t`.`title` AS `track_title`,group_concat(`a`.`name` separator ', ') AS `artists` from ((`tracks` `t` join `tracks_artists` `ta` on((`t`.`track_id` = `ta`.`track_id`))) join `artists` `a` on((`ta`.`artist_id` = `a`.`artist_id`))) group by `t`.`track_id`,`t`.`title` */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-01-24 11:13:36
