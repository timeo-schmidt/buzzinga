import 'package:firebase_messaging/firebase_messaging.dart';
import 'package:flutter/material.dart';
import 'package:isar/isar.dart';
import 'package:path_provider/path_provider.dart';
import 'package:return_success_4_app/controller/message_database_service.dart';
import 'package:return_success_4_app/controller/notification_service.dart';
import 'package:return_success_4_app/model/device_model.dart';
import 'package:return_success_4_app/view/homepage/homepage.dart';
import 'package:firebase_core/firebase_core.dart';
import 'firebase_options.dart';
import 'model/message_model.dart';
import 'view/analyticsPage/analytics.dart';
import 'view/editPage/edit.dart';
import 'view/infoPage/info.dart';
import 'view/settingsPage/settings.dart';

///Callback for when FCM messages are received when the app is either in the background or terminated
Future<void> _firebaseMessagingBackgroundHandler(RemoteMessage message) async {
  // If you're going to use other Firebase services in the background, such as Firestore,
  // make sure you call `initializeApp` before using other Firebase services.
  //await Firebase.initializeApp();
  print("Handling a background message: ${message.messageId}");

  // Opening Isar
  var isar = Isar.getInstance('isar');

  if (isar == null) {
    print("Isar is not open, so opening it.");
    final dir = await getApplicationSupportDirectory();
    isar = await Isar.open(
      schemas: [MessageSchema, DeviceSchema],
      directory: dir.path,
    );
  }

  // Storing the message in the DB
  await MessageDatabaseService()
      .addToMessagesDB(isar, Message.fromJson(message.data));
}

void main() async {
  WidgetsFlutterBinding.ensureInitialized();

  // Initialize Firebase
  await Firebase.initializeApp(
    options: DefaultFirebaseOptions.currentPlatform,
  );
  // Initialize Isar DB
  final dir = await getApplicationSupportDirectory();
  final isar = await Isar.open(
    schemas: [MessageSchema, DeviceSchema],
    directory: dir.path,
  );

  // Initialize Firebase Cloud Messaging (FCM)
  var _fcm = NotificationService();
  _fcm.requestIOSPermissions();
  _fcm.setupHeadsUpNotifications();
  //await _fcm.printToken();
  // Set the foreground callback, for when messages are received and the app is in the foreground
  FirebaseMessaging.onMessage.listen((RemoteMessage message) async {
    // Add message to DB
    MessageDatabaseService()
        .addToMessagesDB(isar, Message.fromJson(message.data));
  });
  // Set the background callback, for when messages are received and the app is either in the background or terminated
  FirebaseMessaging.onBackgroundMessage(_firebaseMessagingBackgroundHandler);
  // Subscribe to general topics
  _fcm.subscribeToTopics(['global']);

  // Run the App
  runApp(MyApp(isar: isar));
}

/// Flutter Material App, root of the application
class MyApp extends StatelessWidget {
  const MyApp({required this.isar, Key? key}) : super(key: key);

  /// Name of the app on the Homepage
  final String appName = "Notisound";

  /// Isar DB instance passed and used around the app
  final Isar isar;

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: appName,
      theme: ThemeData(
        primarySwatch: Colors.blue,
        backgroundColor: Colors.white,
      ),
      initialRoute: '/',
      routes: {
        '/': (context) => HomePage(title: appName, isar: isar),
        '/settings': (context) => SettingsPage(isar: isar),
        '/info': (context) => const InfoPage(),
        '/edit': (context) => EditPage(isar: isar),
        '/analytics': (context) => AnalyticsPage(isar: isar),
      },
    );
  }
}
