import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';

@Component({
  selector: 'page-home',
  templateUrl: 'home.html'
})
export class HomePage {

  constructor(public navCtrl: NavController) {

  }

  private sendWateringSocket(){
    console.log('sending watering socket');
     //var socket = io('http://localhost');
     //socket.emit('my other event');
  }

}
