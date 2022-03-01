import 'package:isar/isar.dart';

part 'message_model.g.dart';

@Collection()
class Message {
  /// Isar ID required to be unique for each object
  @Id()
  int id = Isar.autoIncrement;

  /// Title of the message
  String title;

  /// Category of the message (e.g. 'Doorbell', 'Fire Alarm'...)
  String category;

  /// Content of the message, a description of what is going on
  String content;

  /// Timestamp of the message
  DateTime dateTime;

  /// DeviceID of the device that sent the message
  String author;

  /// Contructor of the Message object
  Message({
    required this.title,
    required this.category,
    required this.content,
    required this.dateTime,
    required this.author,
  });

  /// Converts a given Message to the JSON format
  Map<String, Object?> toJson() {
    return {
      'title': title,
      'category': category,
      'content': content,
      'dateTime': dateTime.toString(),
      'author': author,
    };
  }

  /// Constructs a new Message from the JSON data
  factory Message.fromJson(Map<String, dynamic> data) {
    return Message(
      title: data['title'] ?? 'Unknown title',
      category: data['category'] ?? 'Unknown category',
      content: data['content'] ?? 'No content',
      dateTime: DateTime.now(),
      author: data['author'] ?? 'No author',
    );
  }
}
