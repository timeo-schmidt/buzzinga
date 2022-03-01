import 'package:isar/isar.dart';
import 'package:return_success_4_app/model/device_model.dart';

/// A class handling all transactions to the 'devices' DB using Isar.
class DeviceDatabaseService {
  /// Add the device 'entry' to the DB
  Future<void> addToDevicesDB(Isar isar, Device entry) async {
    // Storing the device in the DB
    int newKey = await isar.writeTxn((isar) async {
      int key = await isar.devices.put(entry);
      return key;
    });
    print(
        "Adding device to devices DB at key: $newKey with deviceId: ${entry.deviceId}");
  }

  /// Add in the DB the given 'topic' to the list of topics of the device with the given 'deviceId'.
  /// Or if no device exists in the DB yet, create one.
  Future<void> addTopicToDevicesDB(
      Isar isar, String deviceId, String topic) async {
    // Find the device if it already exists
    final queriedDevice =
        await isar.devices.filter().deviceIdEqualTo(deviceId).findFirst();

    if (queriedDevice == null) {
      // Create a nex device to host the topic and put it in the DB
      final newDevice = Device(deviceId: deviceId, topics: [topic]);
      // Storing the new device in the DB
      int newKey = await isar.writeTxn((isar) async {
        int key = await isar.devices.put(newDevice);
        return key;
      });
      print("Adding topic to NEW device $deviceId at key: $newKey");
    } else {
      // Add topic to device.topics list
      queriedDevice.topics.add(topic);
      // Storing the new device in the DB
      int newKey = await isar.writeTxn((isar) async {
        int key = await isar.devices.put(queriedDevice);
        return key;
      });
      print(
          "Adding topic to EXISTING device ${queriedDevice.deviceId} at key: $newKey");
    }
  }

  /// Stream all elements of the 'devices' DB
  Stream<List<Device>> streamDevices(Isar isar) {
    return isar.devices.where().build().watch(initialReturn: true);
  }

  /// Remove 1 device from the DB
  Future<void> delete1DeviceFromDB(String deviceId, Isar isar) async {
    // Find the device if it already exists
    final queriedDevice =
        await isar.devices.filter().deviceIdEqualTo(deviceId).findFirst();
    //Delete the entry from the database
    if (queriedDevice != null) {
      await isar.writeTxn((isar) async {
        await isar.devices.delete(queriedDevice.id);
      });
      print(
          "Deleted device ${queriedDevice.deviceId} at key ${queriedDevice.id}");
    }
  }

  /// Clear all the entries of the 'devices' DB!
  Future<void> clearDevicesDB(Isar isar) async {
    //Clear all messages
    await isar.writeTxn((isar) async {
      await isar.devices.clear();
    });
    print("Clearing the devices DB...");
  }
}
