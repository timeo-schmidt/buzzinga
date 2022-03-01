import 'package:flutter/material.dart';
import 'package:isar/isar.dart';
import 'package:return_success_4_app/controller/notification_service.dart';
import 'package:return_success_4_app/view/general_widgets.dart';

import '../../controller/device_database_service.dart';
import '../../model/device_model.dart';

/// Builds a card from a given Device object
Widget deviceCard(Isar isar, Device device) {
  return Container(
    margin: const EdgeInsets.only(left: 12, right: 12, bottom: 12),
    decoration: const BoxDecoration(
      color: Colors.white,
      borderRadius: BorderRadius.all(Radius.circular(20)),
      boxShadow: [
        BoxShadow(
          color: Color.fromARGB(20, 0, 0, 0),
          offset: Offset(2, 2),
          blurRadius: 5,
        ),
      ],
    ),
    child: Row(children: [
      // Icon
      const Padding(
        padding: EdgeInsets.all(10.0),
        child: Icon(
          Icons.developer_board,
          size: 40,
          color: Color.fromARGB(255, 48, 48, 48),
        ),
      ),
      // Message
      Expanded(
        child: Container(
          padding: const EdgeInsets.fromLTRB(0, 15, 0, 15),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Text(
                device.deviceId,
                style:
                    const TextStyle(fontSize: 15, fontWeight: FontWeight.bold),
              ),
              const SizedBox(
                height: 4,
              ),
              ListView.builder(
                  shrinkWrap: true,
                  physics: const NeverScrollableScrollPhysics(),
                  itemCount: device.topics.length,
                  itemBuilder: (BuildContext context, int index) {
                    return Row(children: [
                      const Text(
                        "using mode: ",
                        style: TextStyle(color: Colors.grey),
                      ),
                      Text(device.topics[index]),
                    ]);
                  })
            ],
          ),
        ),
      ),
      // Icon
      Padding(
        padding: const EdgeInsets.all(15.0),
        child: iconButton(
            size: 30,
            icon: Icons.delete_outlined,
            color: const Color.fromARGB(255, 190, 63, 63),
            onPressed: () {
              DeviceDatabaseService()
                  .delete1DeviceFromDB(device.deviceId, isar);
              List<String> topicList = [];
              for (String topic in device.topics) {
                final newTopic = device.deviceId + "_" + topic;
                topicList.add(newTopic);
              }
              NotificationService().unsubscribeFromTopics(topicList);
            }),
      ),
    ]),
  );
}

/// Builds a list of all Devices stored by the app
class SubscribedList extends StatelessWidget {
  const SubscribedList({required this.isar, Key? key}) : super(key: key);

  final Isar isar;

  @override
  Widget build(BuildContext context) {
    return StreamBuilder(
      stream: DeviceDatabaseService().streamDevices(isar),
      builder: (context, AsyncSnapshot<List<Device>> snapshot) {
        if (snapshot.hasData) {
          if (snapshot.data!.isEmpty) {
            return SizedBox(
              width: double.infinity,
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.center,
                children: const [
                  SizedBox(
                    height: 50,
                  ),
                  Text(
                    "No devices registered yet.",
                    style: TextStyle(fontSize: 16, color: Colors.grey),
                  ),
                  SizedBox(height: 8),
                  Text(
                    "Add one using the form above.",
                    style: TextStyle(fontSize: 16, color: Colors.grey),
                  ),
                ],
              ),
            );
          } else {
            return ListView.builder(
              reverse: true,
              shrinkWrap: true,
              physics: const NeverScrollableScrollPhysics(),
              itemCount: snapshot.data!.length,
              itemBuilder: (BuildContext context, int index) {
                return deviceCard(
                  isar,
                  snapshot.data![index],
                );
              },
            );
          }
        } else {
          return const Center(child: CircularProgressIndicator());
        }
      },
    );
  }
}
