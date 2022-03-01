import 'package:isar/isar.dart';
import 'package:return_success_4_app/model/message_model.dart';

/// A class handling all transactions to the 'messages' DB using Isar
class MessageDatabaseService {
  /// Add the entry to the 'messages' DB
  Future<void> addToMessagesDB(Isar isar, Message entry) async {
    // Storing the message in the DB
    int newKey = await isar.writeTxn((isar) async {
      int key = await isar.messages.put(entry);
      return key;
    });
    print(
        "Adding message to messages DB at key: $newKey with title: ${entry.title}");
  }

  /// Stream all elements of the 'messages' DB
  Stream<List<Message>> streamMessages(Isar isar) {
    return isar.messages.where().build().watch(initialReturn: true);
  }

  /// Clear all the entries of the 'messages' DB!
  Future<void> clearMessagesDB(Isar isar) async {
    //Clear all messages
    await isar.writeTxn((isar) async {
      await isar.messages.clear();
    });
    print("Clearing the messages DB...");
  }
}
