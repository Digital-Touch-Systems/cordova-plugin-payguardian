plugman uninstall --platform ios --project ./platforms/ios --plugin com.bridgepaynetwork.payguardian
plugman install --platform ios --plugin "$( dirname "${BASH_SOURCE[0]}" )" --project ./platforms/ios/
